#ifndef YNET_CONNECTION_HPP
#define YNET_CONNECTION_HPP

#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

#include <memory>
#include <iostream>

#include "Message.hpp"
#include "ThreadSafeQueue.hpp"

namespace Ynet{

	template<typename T>
	class ServerInterface;
	template<typename T>
	class Connection : public std::enable_shared_from_this<Connection<T>>
	{
	public:
		enum class Owner
		{
			Server,
			Client
		};
		public:
		Connection(Owner parent, asio::io_context& asioContext, asio::ip::tcp::socket socket, ThreadSafeQueue<OwnedMessage<T>>& qIn)
			: m_asioContext(asioContext), m_socket(std::move(socket)), m_qMessagesIn(qIn)
		{
			m_nOwnerType = parent;

			if(m_nOwnerType == Owner::Server){
				m_nHandshakeOut = std::uint64_t(std::chrono::system_clock::now().time_since_epoch().count());
				m_nHandshakeCheck = scramble(m_nHandshakeOut);
			}
			else{
				m_nHandshakeIn = 0;
				m_nHandshakeOut = 0;
			}


		}
			virtual ~Connection()
		{}
		uint32_t getId() const
		{
			return id;
		}
		public:
		void connectToClient(Ynet::ServerInterface<T>* server,  uint32_t uid = 0)
		{
			if (m_nOwnerType == Owner::Server)
			{
				if (m_socket.is_open())
				{
					id = uid;
					writeValidation();

					readValidation(server);
				}
			}
		}

		void connectToServer(const asio::ip::tcp::resolver::results_type& endpoints)
		{
			// Only clients can connect to servers
			if (m_nOwnerType == Owner::Client)
			{
				// Request asio attempts to connect to an endpoint
				asio::async_connect(m_socket, endpoints,
					[this](std::error_code ec, asio::ip::tcp::endpoint endpoint)
					{
						if (!ec)
						{
							readValidation();
						}
					});
			}
		}

		void disconnect()
		{
			if (isConnected())
				asio::post(m_asioContext, [this]() { m_socket.close(); });
		}

		bool isConnected() const
		{
			return m_socket.is_open();
		}

		void StartListening()
		{
			
		}
		public:
		void send(const Message<T>& msg)
		{
			asio::post(m_asioContext,
				[this, msg]()
				{
					bool bWritingMessage = !m_qMessagesOut.empty();
					m_qMessagesOut.push_back(msg);
					if (!bWritingMessage)
					{
						writeHeader();
					}
				});
		}

		private:
		void writeHeader()
		{
			asio::async_write(m_socket, asio::buffer(&m_qMessagesOut.front().header, sizeof(MessageHeader<T>)),
				[this](std::error_code ec, std::size_t length)
				{
					// asio has now sent the bytes - if there was a problem
					// an error would be available...
					if (!ec)
					{
						// ... no error, so check if the Message header just sent also
						// has a Message body...
						if (m_qMessagesOut.front().body.size() > 0)
						{
							writeBody();
						}
						else
						{
							m_qMessagesOut.pop_front();
							if (!m_qMessagesOut.empty())
							{
								writeHeader();
							}
						}
					}
					else
					{
						std::cout << "[" << id << "] Write Header Fail.\n";
						m_socket.close();
					}
				});
		}
		void writeBody()
		{
			asio::async_write(m_socket, asio::buffer(m_qMessagesOut.front().body.data(), m_qMessagesOut.front().body.size()),
				[this](std::error_code ec, std::size_t length)
				{
					if (!ec)
					{
						m_qMessagesOut.pop_front();
						if (!m_qMessagesOut.empty())
						{
							writeHeader();
						}
					}
					else
					{
						// Sending failed, see writeHeader() equivalent for description :P
						std::cout << "[" << id << "] Write Body Fail.\n";
						m_socket.close();
					}
				});
		}
		void readHeader()
		{
			asio::async_read(m_socket, asio::buffer(&m_msgTemporaryIn.header, sizeof(MessageHeader<T>)),
				[this](std::error_code ec, std::size_t length)
				{						
					if (!ec)
					{
						if (m_msgTemporaryIn.header.size > 0)
						{
							m_msgTemporaryIn.body.resize(m_msgTemporaryIn.header.size);
							readBody();
						}
						else
						{
							addToIncomingMessageQueue();
						}
					}
					else
					{
						std::cout << "[" << id << "] Read Header Fail.\n";
						m_socket.close();
					}
				});
		}
		void readBody()
		{
			asio::async_read(m_socket, asio::buffer(m_msgTemporaryIn.body.data(), m_msgTemporaryIn.body.size()),
				[this](std::error_code ec, std::size_t length)
				{						
					if (!ec)
					{
						addToIncomingMessageQueue();
					}
					else
					{
						std::cout << "[" << id << "] Read Body Fail.\n";
						m_socket.close();
					}
				});
		}
		void addToIncomingMessageQueue()
		{				
			if(m_nOwnerType == Owner::Server)
				m_qMessagesIn.push_back({ this->shared_from_this(), m_msgTemporaryIn });
			else
				m_qMessagesIn.push_back({ nullptr, m_msgTemporaryIn });
			readHeader();
		}

		std::uint64_t scramble(std::uint64_t nInput){
			std::uint64_t out = nInput ^ 0xAEADBEEFC0DEAAAA;
			out = (out & 0xF0F0F0F0F0F0F0) >> 4 | (out & 0x0F0F0F0F0F0F0F) << 4;
			return out ^ 0xC0DEFACE12345678;
		}

		void writeValidation(){
			asio::async_write(m_socket, asio::buffer(&m_nHandshakeOut, sizeof(std::uint64_t)),
				[this](std::error_code ec,[[maybe_unused]] std::size_t length){
					if(!ec){
						if(m_nOwnerType == Owner::Client){
							readHeader();
						}
					}
					else{
						m_socket.close();
					}
				}	
			);
		}

		void readValidation(class Ynet::ServerInterface<T>* server = nullptr ){
			asio::async_read(m_socket, asio::buffer(&m_nHandshakeIn, sizeof(std::uint64_t)),
				[this,server](std::error_code ec, std::size_t lenght){
					if(!ec){
						if(m_nOwnerType == Owner::Server){

							if(m_nHandshakeIn == m_nHandshakeCheck){
								std::cout << "Client Validated" << std::endl;
								server->onClientValidated(this->shared_from_this());

								readHeader();
							}
							else{
								std::cout << "Client disconnected(fail validation) " << std::endl;
								m_socket.close();
							}
						}
						else{
							m_nHandshakeOut = scramble(m_nHandshakeIn);
							writeValidation();
						}
					}
					else{
						std::cout << "Client Disconnected( readValidation)" << std::endl;
						m_socket.close();
					}
				}
			);

		}


	protected:
		asio::ip::tcp::socket m_socket;
		asio::io_context& m_asioContext;
		ThreadSafeQueue<Message<T>> m_qMessagesOut;
		ThreadSafeQueue<OwnedMessage<T>>& m_qMessagesIn;
		Message<T> m_msgTemporaryIn;
		Owner m_nOwnerType = Owner::Server;
		uint32_t id = 0;

		std::uint64_t m_nHandshakeOut = 0;
		std::uint64_t m_nHandshakeIn = 0;
		std::uint64_t m_nHandshakeCheck = 0;
	};
};

#include "Server.hpp"

#endif //CONNECTION
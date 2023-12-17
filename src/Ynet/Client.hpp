#ifndef YNET_CLIENT_HPP
#define YNET_CLIENT_HPP

#include "Connection.hpp"
#include "iostream"
namespace Ynet{
	template <typename T>
	class ClientInterface
	{
	public:
		ClientInterface() 
		{}
		virtual ~ClientInterface()
		{
			// If the client is destroyed, always try and disconnect from server
			disconnect();
		}
	public:
		// connect to server with hostname/ip-address and port
		bool connect(const std::string& host, const uint16_t port)
		{
			try
			{
				// Resolve hostname/ip-address into tangiable physical address
				asio::ip::tcp::resolver resolver(m_context);
				asio::ip::tcp::resolver::results_type endpoints = resolver.resolve(host, std::to_string(port));
				// Create Connection
				m_connection = std::make_unique<Connection<T>>(Connection<T>::Owner::Client, m_context, asio::ip::tcp::socket(m_context), m_qMessagesIn);
				// Tell the Connection object to connect to server
				std::atomic flag1{false};
				std::atomic flag2{false};
				m_connection->connectToServer(endpoints,flag1, flag2);

				// Start Context Thread
				thrContext = std::thread([this]() { m_context.run(); });

				while(true){
					std::cout << "waiting for response" << std::endl;
					if(flag1){
						return true;
					}
					if(flag2){
						return false;
					}
				}
			
			}
			catch (std::exception& e)
			{
				std::cerr << "Client Exception: " << e.what() << "\n";
				return false;
			}
			return true;
		}
		// disconnect from server
		void disconnect()
		{
			// If Connection exists, and it's connected then...
			if(isConnected())
			{
				// ...disconnect from server gracefully
				m_connection->disconnect();
			}
			// Either way, we're also done with the asio context...				
			m_context.stop();
			// ...and its thread
			if (thrContext.joinable())
				thrContext.join();
			// Destroy the Connection object
			m_connection.release();
		}
		// Check if client is actually connected to a server
		bool isConnected()
		{
			if (m_connection)
				return m_connection->isConnected();
			else
				return false;
		}
	public:
		// send message to server
		void send(const Message<T>& msg)
		{
			if (isConnected())
				 m_connection->send(msg);
		}
		// Retrieve queue of messages from server
		ThreadSafeQueue<OwnedMessage<T>>& incoming()
		{ 
			return m_qMessagesIn;
		}
	protected:
		// asio context handles the data transfer...
		asio::io_context m_context;
		// ...but needs a thread of its own to execute its work commands
		std::thread thrContext;
		// The client has a single instance of a "Connection" object, which handles data transfer
		std::unique_ptr<Connection<T>> m_connection;
		
	private:
		// This is the thread safe queue of incoming messages from server
		ThreadSafeQueue<OwnedMessage<T>> m_qMessagesIn;
	};
	
}

#endif //YNET_CLIENT_HPP
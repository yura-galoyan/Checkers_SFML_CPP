#ifndef YNET_SERVER_HPP
#define YNET_SERVER_HPP

#include <deque>

#include "Connection.hpp"

#include <iostream>
namespace Ynet{
	template<typename T>
	class ServerInterface
	{
	public:
		// Create a server, ready to listen on specified port
		ServerInterface(uint16_t port)
			: m_asioAcceptor(m_asioContext, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port))
		{
		}
		virtual ~ServerInterface()
		{
			// May as well try and tidy up
			stop();
		}
		// Starts the server!
		bool start()
		{
			try
			{
				// Issue a task to the asio context - This is important
				// as it will prime the context with "work", and stop it
				// from exiting immediately. Since this is a server, we 
				// want it primed ready to handle clients trying to
				// connect.
				waitForClientConnection();
				// Launch the asio context in its own thread
				m_threadContext = std::thread([this]() { m_asioContext.run(); });
			}
			catch (std::exception& e)
			{
				// Something prohibited the server from listening
				std::cerr << "[SERVER] Exception: " << e.what() << "\n";
				return false;
			}
			std::cout << "[SERVER] Started!\n";
			return true;
		}
		// Stops the server!
		void stop()
		{
			// Request the context to close
			m_asioContext.stop();
			// Tidy up the context thread
			if (m_threadContext.joinable()) m_threadContext.join();
			// Inform someone, anybody, if they care...
			std::cout << "[SERVER] Stopped!\n";
		}
		// ASYNC - Instruct asio to wait for Connection
		void waitForClientConnection()
		{
			// Prime context with an instruction to wait until a socket connects. This
			// is the purpose of an "acceptor" object. It will provide a unique socket
			// for each incoming Connection attempt
			m_asioAcceptor.async_accept(
				[this](std::error_code ec, asio::ip::tcp::socket socket)
				{
					// Triggered by incoming Connection request
					if (!ec)
					{
						// Display some useful(?) information
						std::cout << "[SERVER] New Connection: " << socket.remote_endpoint() << "\n";
						// Create a new Connection to handle this client 
						std::shared_ptr<Connection<T>> newconn = 
							std::make_shared<Connection<T>>(Connection<T>::Owner::Server, 
								m_asioContext, std::move(socket), m_qMessagesIn);
						
						
						// Give the user server a chance to deny Connection
						if (onClientConnect(newconn))
						{								
							// Connection allowed, so add to container of new connections
							m_deqConnections.push_back(std::move(newconn));
							// And very important! Issue a task to the Connection's
							// asio context to sit and wait for bytes to arrive!
							m_deqConnections.back()->connectToClient(this,nIDCounter++);
							std::cout << "[" << m_deqConnections.back()->getId() << "] Connection Approved\n";
						}
						else
						{
							std::cout << "[-----] Connection Denied\n";
							// Connection will go out of scope with no pending tasks, so will
							// get destroyed automagically due to the wonder of smart pointers
						}
					}
					else
					{
						// Error has occurred during acceptance
						std::cout << "[SERVER] New Connection Error: " << ec.message() << "\n";
					}
					// Prime the asio context with more work - again simply wait for
					// another Connection...
					waitForClientConnection();
				});
		}
		// Send a message to a specific client
		void messageClient(std::shared_ptr<Connection<T>> client, const Message<T>& msg)
		{
			// Check client is legitimate...
			if (client && client->isConnected())
			{
				// ...and post the message via the Connection
				client->Send(msg);
			}
			else
			{
				// If we cant communicate with client then we may as 
				// well remove the client - let the server know, it may
				// be tracking it somehow
				onClientDisconnect(client);
				// Off you go now, bye bye!
				client.reset();
				// Then physically remove it from the container
				m_deqConnections.erase(
					std::remove(m_deqConnections.begin(), m_deqConnections.end(), client), m_deqConnections.end());
			}
		}
		
		// Send message to all clients
		void messageAllClients(const Message<T>& msg, std::shared_ptr<Connection<T>> pIgnoreClient = nullptr)
		{
			bool bInvalidClientExists = false;
			// Iterate through all clients in container
			for (auto& client : m_deqConnections)
			{
				// Check client is connected...
				if (client && client->isConnected())
				{
					// ..it is!
					if(client != pIgnoreClient)
						client->send(msg);
				}
				else
				{
					// The client couldnt be contacted, so assume it has
					// disconnected.
					onClientDisconnect(client);
					client.reset();
					// Set this flag to then remove dead clients from container
					bInvalidClientExists = true;
				}
			}
			// Remove dead clients, all in one go - this way, we dont invalidate the
			// container as we iterated through it.
			if (bInvalidClientExists)
				m_deqConnections.erase(
					std::remove(m_deqConnections.begin(), m_deqConnections.end(), nullptr), m_deqConnections.end());
		}
		// Force server to respond to incoming messages
		void update(size_t nMaxMessages = -1, bool bWait = false)
		{
			if (bWait) m_qMessagesIn.wait();
			size_t nMessageCount = 0;
			while (nMessageCount < nMaxMessages && !m_qMessagesIn.empty())
			{
				// Grab the front message
				auto msg = m_qMessagesIn.pop_front();
				// Pass to message handler
				onMessage(msg.remote, msg.msg);
				++nMessageCount;
			}
		}
	protected:
		// This server class should override thse functions to implement
		// customised functionality
		// Called when a client connects, you can veto the Connection by returning false
		virtual bool onClientConnect(std::shared_ptr<Connection<T>> client)
		{
			return false;
		}
		// Called when a client appears to have disconnected
		virtual void onClientDisconnect(std::shared_ptr<Connection<T>> client)
		{
		}
		// Called when a message arrives
		virtual void onMessage(std::shared_ptr<Connection<T>> client, Message<T>& msg)
		{
		}

	public:
		virtual void onClientValidated(std::shared_ptr<Connection<T>> client){
			
		}
	protected:
		// Thread Safe Queue for incoming message packets
		ThreadSafeQueue<OwnedMessage<T>> m_qMessagesIn;
		// Container of active validated connections
		std::deque<std::shared_ptr<Connection<T>>> m_deqConnections;
		// Order of declaration is important - it is also the order of initialisation
		asio::io_context m_asioContext;
		std::thread m_threadContext;
		// These things need an asio context
		asio::ip::tcp::acceptor m_asioAcceptor; // Handles new incoming Connection attempts...
		// Clients will be identified in the "wider system" via an ID
		uint32_t nIDCounter = 10000;
	};
}
#endif //YNET_SERVER_HPP
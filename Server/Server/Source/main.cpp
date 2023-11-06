#include "../../Utils/Ynet/Server.hpp"

#include "../Common.hpp"

class CustomServer : public Ynet::ServerInterface<ChessMsgTypes>
{
public:
    CustomServer(std::uint16_t nPort) : Ynet::ServerInterface<ChessMsgTypes>(nPort)
    {

    }

protected:
    virtual bool onClientConnect(std::shared_ptr<Ynet::Connection<ChessMsgTypes>> client)
    {
        Ynet::Message<ChessMsgTypes> msg;
		msg.header.id = ChessMsgTypes::ServerAccept;
		client->send(msg);
		return true;
    }

    virtual void onClientDisconnect(std::shared_ptr<Ynet::Connection<ChessMsgTypes>> client)
    {
        std::cout << "Removing client [" << client->getId() << "]\n";
    }

    virtual void onMessage(std::shared_ptr<Ynet::Connection<ChessMsgTypes>> client, Ynet::Message<ChessMsgTypes>& msg)
    {
        switch (msg.header.id)
        {
        case ChessMsgTypes::ServerPing:
            std::cout << "[" << client->getId() << "]: Server Ping" << std::endl;
            client->send(msg);
            break;
        case ChessMsgTypes::MessageAll:
        {
            std::cout << "[" << client->getId() << "]: Message All\n";

			// Construct a new message and send it to all clients
			Ynet::Message<ChessMsgTypes> msg;
			msg.header.id = ChessMsgTypes::ServerMessage;
			msg << client->getId();
			messageAllClients(msg, client);

        }
        default:
            break;
        }
    }

};

int main(){
    CustomServer server(60000);
    server.start();

    while(1)
    {
        server.update(-1,true);
    } 
    return 0;
}

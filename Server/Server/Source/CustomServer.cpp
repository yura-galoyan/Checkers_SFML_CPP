
#include "CustomServer.hpp"

CustomServer::CustomServer(std::uint16_t nPort) : CheckersServer(nPort)
{
    players[0].id = 0;
    players[0].color = Color::None;

    players[1].id = 0;
    players[1].color = Color::None;

}

void CustomServer::onClientValidated(std::shared_ptr<CheckersConnection> client)  {
    Ynet::Message<CheckersMsgType> msg;

    if(players[0].color == Color::None){
        std::cout << "creating player 1" << std::endl;
        players[0].id = 1;
        players[0].color = Color::White;

        std::cout << "id is: " << players[0].id << std::endl;

        if(players[0].color == Color::White){
            std::cout << "white " << std::endl;
        }
        if(players[1].color == Color::Black){
            std::cout << "black " << std::endl;
        }

        msg.header.id = CheckersMsgType::Assign_id;
        msg << players[0];

        std::cout << "msg size" << msg.body.size() << std::endl;


        client->send(msg);
        std::cout << "sending first player data" <<std::endl;
        return;
    }
    if(players[1].color == Color::None){
        std::cout << "creating player 2 " << std::endl;
        players[1].id = 2;
        players[1].color = Color::Black;
        msg.header.id = CheckersMsgType::Assign_id;
        msg << players[1];
        client->send(msg);


        Ynet::Message<CheckersMsgType> msg2;
        msg2.header.id = CheckersMsgType::OtherPlayer;
        msg2 << players[1];
        std::cout << "sending second player data" << std::endl;
        messageAllClients(msg2,client);
        std::cout << "notifying first player that second player is ready" << std::endl;


        return;
    }
    

}

bool CustomServer::onClientConnect(std::shared_ptr<Ynet::Connection<CheckersMsgType>> client)
{
    Ynet::Message<CheckersMsgType> msg;
	msg.header.id = CheckersMsgType::ServerAccept;
	client->send(msg);
	return true;
}

void CustomServer::onClientDisconnect(std::shared_ptr<Ynet::Connection<CheckersMsgType>> client)
{
    std::cout << "Removing client [" << client->getId() << "]\n";
}

void CustomServer::onMessage(std::shared_ptr<Ynet::Connection<CheckersMsgType>> client, Ynet::Message<CheckersMsgType>& msg)
{
    switch (msg.header.id)
    {
    case CheckersMsgType::ServerPing:
        std::cout << "[" << client->getId() << "]: Server Ping" << std::endl;
        client->send(msg);
        break;
    case CheckersMsgType::MessageAll:
    {
        std::cout << "[" << client->getId() << "]: Message All\n";
		// Construct a new message and send it to all clients
		Ynet::Message<CheckersMsgType> msg;
		msg.header.id = CheckersMsgType::ServerMessage;
		msg << client->getId();
		messageAllClients(msg, client);
    }
        break;
    case CheckersMsgType::Player1:
    {
        std::cout << "[" << client->getId() << "]: is Readey\n";
    }
        break;
    default:
        break;
    }
}
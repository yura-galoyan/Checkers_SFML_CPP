
#include "CustomServer.hpp"

CustomServer::CustomServer(std::uint16_t nPort) : Ynet::ServerInterface<ChessMsgTypes>(nPort)
{
    players[0].id = 0;
    players[0].color = Color::None;

    players[1].id = 0;
    players[1].color = Color::None;

}

void CustomServer::onClientValidated(std::shared_ptr<Ynet::Connection<ChessMsgTypes>> client)  {
    Ynet::Message<ChessMsgTypes> msg;
    if(players[0].color == Color::None){
        players[0].id = 1;
        players[0].color = Color::White;
        msg.header.id = ChessMsgTypes::Assign_id;
        msg << players[0];
        client->send(msg);
        std::cout << "sending first player data" <<std::endl;
        return;
    }
    if(players[1].color == Color::None){
        players[1].id = 2;
        players[1].color = Color::Black;
        msg.header.id = ChessMsgTypes::Assign_id;
        msg << players[1];
        client->send(msg);
        std::cout << "sending second player data" << std::endl;
        return;
    }
    

}

bool CustomServer::onClientConnect(std::shared_ptr<Ynet::Connection<ChessMsgTypes>> client)
{
    Ynet::Message<ChessMsgTypes> msg;
	msg.header.id = ChessMsgTypes::ServerAccept;
	client->send(msg);
	return true;
}

void CustomServer::onClientDisconnect(std::shared_ptr<Ynet::Connection<ChessMsgTypes>> client)
{
    std::cout << "Removing client [" << client->getId() << "]\n";
}

void CustomServer::onMessage(std::shared_ptr<Ynet::Connection<ChessMsgTypes>> client, Ynet::Message<ChessMsgTypes>& msg)
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
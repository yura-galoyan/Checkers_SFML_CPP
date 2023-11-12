#ifndef CUSTOM_SERVER_HPP
#define CUSTOM_SERVER_HPP

#include "../../Utils/Ynet/Server.hpp"
#include "../../Common.hpp"

#include <array>

class CustomServer : public Ynet::ServerInterface<ChessMsgTypes>
{
public:
    CustomServer(std::uint16_t nPort);

protected:
	void onClientValidated(std::shared_ptr<Ynet::Connection<ChessMsgTypes>> client) override;
    bool onClientConnect(std::shared_ptr<Ynet::Connection<ChessMsgTypes>> client) override;
    void onClientDisconnect(std::shared_ptr<Ynet::Connection<ChessMsgTypes>> client) override;
    void onMessage(std::shared_ptr<Ynet::Connection<ChessMsgTypes>> client, Ynet::Message<ChessMsgTypes>& msg) override;

private:
    std::array<Player,2> players;


};

#endif  //CUSTOM_SERVER_HPP
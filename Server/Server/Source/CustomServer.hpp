#ifndef CUSTOM_SERVER_HPP
#define CUSTOM_SERVER_HPP

#include "../../../Utils/Ynet/Server.hpp" 
#include "../../../Common/Common.hpp"
#include <array>
using CheckersServer = Ynet::ServerInterface<CheckersMsgType>;
using CheckersConnection = Ynet::Connection<CheckersMsgType>;
class CustomServer : public CheckersServer
{
public:
    CustomServer(std::uint16_t nPort);

protected:
	void onClientValidated(std::shared_ptr<CheckersConnection> client) override;
    bool onClientConnect(std::shared_ptr<CheckersConnection> client) override;
    void onClientDisconnect(std::shared_ptr<CheckersConnection> client) override;
    void onMessage(std::shared_ptr<CheckersConnection> client, Ynet::Message<CheckersMsgType>& msg) override;

private:
    std::array<Player,2> players;


};

#endif  //CUSTOM_SERVER_HPP
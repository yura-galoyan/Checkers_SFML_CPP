#ifndef CONTOLLERS_GAME_LOBBY_CONTOLLER_HPP
#define CONTOLLERS_GAME_LOBBY_CONTOLLER_HPP

#include "../ApplicartionProtocol.hpp"
#include "../../Common/Common.hpp"

#include "iController.hpp"

#include <memory>

class GameLobbyController : public iController
{
public:
    GameLobbyController(EventPoller* eventPoller);
    void onLoad() override; 

    void handleEvents(Window& window) override;
    void registerToServer();
    auto getFirstPlayerId() { return player1.id; }
    auto getSecondPlayerId() { return player2.id; }
    bool isReady() { return player1.id != 0;}
    bool isGameReady();
    

private:
    Player player1{0,Color::None};
    Player player2{0,Color::None};
   // client server stuff

    bool bIsGameReady{false};

    std::unique_ptr<ApplicartionProtocol> clientServer;

};


#endif //CONTOLLERS_GAME_LOBBY_CONTOLLER_HPP
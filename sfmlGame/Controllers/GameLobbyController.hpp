#ifndef CONTOLLERS_GAME_LOBBY_CONTOLLER_HPP
#define CONTOLLERS_GAME_LOBBY_CONTOLLER_HPP

#include "iController.hpp"

class GameLobbyController : public iController
{
public:
    GameLobbyController(Window& window, Event& event);

    void handleEvents() override;
        

};


#endif //CONTOLLERS_GAME_LOBBY_CONTOLLER_HPP
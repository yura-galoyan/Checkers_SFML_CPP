#ifndef STATES_GAME_LOBBY_STATE_HPP
#define STATES_GAME_LOBBY_STATE_HPP

#include "iGameState.hpp"

#include "../Controllers/GameLobbyController.hpp"
#include "../Views/GameLobbyView.hpp"
#include "../Board/BackGround.hpp"
#include "../Ynet/Client.hpp"


class GameLobbyState : public iGameState
{
public:
    GameLobbyState(Application* app, Window& window, Event& event);

    void start() override;

private:
    // some connection
    BackGround m_background; // this is rendering part
    // model
    Application* m_app;
    Window& m_window;
    Event& m_event;
   // Ynet::C


};

#endif //STATES_GAME_LOBBY_STATE_HPP
#ifndef STATES_GAME_LOBBY_STATE_HPP
#define STATES_GAME_LOBBY_STATE_HPP

#include "iGameState.hpp"

class GameLobbyState : public iGameState
{
public:
    GameLobbyState(Application* app, std::unique_ptr<iController> controller, Window& window, Event& event)
        : m_app{app},iGameState(std::move(controller)), m_event{event}, m_window{window} {};
    void start() override;
}

#endif //STATES_GAME_LOBBY_STATE_HPP
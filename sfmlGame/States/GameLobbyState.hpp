#ifndef STATES_GAME_LOBBY_STATE_HPP
#define STATES_GAME_LOBBY_STATE_HPP

#include "iGameState.hpp"

#include "../Board/BackGround.hpp"
#include "../Ynet/Client.hpp"


class GameLobbyState : public iGameState
{
public:
    GameLobbyState(Application* app, std::unique_ptr<iController> controller, Window& window, Event& event)
        : m_app{app},iGameState(std::move(controller)), m_event{event}, m_window{window} {};
    void start() override;

private:
    BackGround m_background;
    Ynet::C


}

#endif //STATES_GAME_LOBBY_STATE_HPP
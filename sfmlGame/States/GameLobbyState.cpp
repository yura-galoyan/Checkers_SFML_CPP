#include "GameLobbyState.hpp"

GameLobbyState::GameLobbyState(Application* app, Window& window, Event& event)
    : m_app{app},
    iGameState(
            std::make_unique<GameLobbyController>(window,event),
            std::make_unique<GameLobbyView>()), 
            m_event{event}, m_window{window} 
        {
            
        };




void GameLobbyState::start()
{
}

#include "GameLobbyState.hpp"

GameLobbyState::GameLobbyState(Application* app,TextureHolder textures, Window& window, EventPoller& eventPoller)
    : m_app{app},
    iGameState(
            std::make_unique<GameLobbyController>(),
            std::make_unique<GameLobbyView>(std::move(textures)),
            &window
        )
        {
            
        };




void GameLobbyState::start()
{
}

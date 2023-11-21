#include "GameLobbyState.hpp"

GameLobbyState::GameLobbyState(Application* app,TextureHolderPtr textures, Window& window, EventPoller* eventPoller)
    : m_app{app},
    iGameState(
            std::make_unique<GameLobbyController>(eventPoller),
            std::make_unique<GameLobbyView>(std::move(textures)),
            &window
        )
        {
            
        };




void GameLobbyState::start()
{
}

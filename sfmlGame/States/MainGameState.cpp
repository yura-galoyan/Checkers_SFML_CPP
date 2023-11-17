#include "MainGameState.hpp"

#include "../Controllers/MainGameController.hpp"
#include "../Views/MainGameView.hpp"

MainGameState::MainGameState(Application* app,  TextureHolder textures, Window& window, EventPoller& eventPoller)
    : m_app{app},
    iGameState(
        std::make_unique<MainGameController>(eventPoller),
        std::make_unique<MainGameView>(std::move(textures)),
        &window
        )
{
    
}


void MainGameState::start()
{
    
}

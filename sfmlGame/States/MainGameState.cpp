#include "MainGameState.hpp"

#include "../Controllers/MainGameController.hpp"
#include "../Views/MainGameView.hpp"

MainGameState::MainGameState(Application* app,Window& window, Event& event)
    : m_app{app},
    iGameState(
        std::make_unique<MainGameController>(window,event),
        std::make_unique<MainGameView>()
        )
{
    
}


void MainGameState::start()
{
    
}

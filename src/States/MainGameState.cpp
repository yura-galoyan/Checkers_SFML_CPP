#include "MainGameState.hpp"

#include "../Controllers/MainGameController.hpp"
#include "../Views/MainGameView.hpp"

MainGameState::MainGameState(Application* app,  TextureHolderPtr textures,FontsHolderPtr fonts, Window& window, EventPoller* eventPoller)
    : m_app{app},
    iGameState(
        std::make_unique<MainGameController>(eventPoller),
        std::make_unique<MainGameView>(std::move(textures), std::move(fonts)),
        &window
        )
{
    
}


void MainGameState::start()
{
    while(m_window->isOpen()){
        m_controller->handleEvents(*m_window);
        m_window->clear();
        m_view->render(*m_window);


        m_window->display();



        std::cout << "Game is Running" << std::endl;
    }
}

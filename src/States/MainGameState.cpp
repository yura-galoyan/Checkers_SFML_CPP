#include "MainGameState.hpp"

#include "../Controllers/MainGameController.hpp"
#include "../Views/MainGameView.hpp"

MainGameState::MainGameState(Application* app,  TextureHolderPtr textures,FontsHolderPtr fonts, Window& window,
                             EventPoller* eventPoller, std::unique_ptr<ApplicationProtocol> clientServer, Player player1, Player player2)
    : m_app{app},
    iGameState(
        std::make_unique<MainGameController>(eventPoller, std::move(clientServer), player1, player2),
        std::make_unique<MainGameView>(std::move(textures), std::move(fonts)),
        &window
        )
{
    m_view->init();
}


void MainGameState::start()
{
    while(m_window->isOpen()){
        m_controller->handleEvents(*m_window);
        m_window->clear();
        m_view->render(*m_window);
        m_window->display();
    }
}

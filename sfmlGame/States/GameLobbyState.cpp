#include "GameLobbyState.hpp"

GameLobbyState::GameLobbyState(Application* app,TextureHolderPtr textures, FontsHolderPtr fonts, Window& window, EventPoller* eventPoller)
    : m_app{app},
    iGameState(
            std::make_unique<GameLobbyController>(eventPoller),
            std::make_unique<GameLobbyView>(std::move(textures)),
            &window
        )
{
    m_view->init();
};

void GameLobbyState::start()
{



    while(m_window->isOpen()){
        m_controller->handleEvents(*m_window);

        m_window->clear();


        m_view->render(*m_window);



        m_window->display();


    }
}

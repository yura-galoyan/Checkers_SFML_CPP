#include "GameLobbyState.hpp"
#include "MainGameState.hpp"

#include <iostream>

GameLobbyState::GameLobbyState(Application* app,TextureHolderPtr textures, FontsHolderPtr fonts, Window& window, EventPoller* eventPoller)
    : m_app{app},
    iGameState(
            std::make_unique<GameLobbyController>(eventPoller),
            std::make_unique<GameLobbyView>(std::move(textures), std::move(fonts)),
            &window
        )
{
    m_view->init();
};

void GameLobbyState::start()
{

    m_controller->onLoad();
    bool flag = false;
    while(m_window->isOpen() && flag == false){
        m_controller->handleEvents(*m_window);
        m_window->clear();
        m_view->render(*m_window);

        auto& GLController = dynamic_cast<GameLobbyController&>(*m_controller);
        auto& GLView = dynamic_cast<GameLobbyView&>(*m_view);
        GLView.setReady(
                GLController.getFirstPlayerId(),
                GLController.isReady()
            );

        if(GLController.isGameReady()){
            flag = true;
            std::cout << "second is also ready" << std::endl;
            GLView.setReady(GLController.getSecondPlayerId(), true);

            std::cout <<"second is" << GLController.getSecondPlayerId() << std::endl;

        }


        m_window->display();
    }

    std::cout << "LETS GOOOOOOOOOOOOOOOO!!!!!!!!!!!!!!!!!" << std::endl;
    auto nextState = std::make_unique<MainGameState>(m_app, m_view->stealTextures(),m_view->stealFonts(),*m_window, m_controller->getEventPoller(),m_controller->stealApplicationProtocol(), m_controller->getPlayer1(), m_controller->getPlayer2() );
    m_app->setState(std::move(nextState));
    m_app->exec();
}

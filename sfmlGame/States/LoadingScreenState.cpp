#include "LoadingScreenState.hpp"

#include <SFML/Graphics.hpp>


#include "../Controllers/iController.hpp"
#include "../Controllers/LoadingScreenController.hpp"

#include "GameLobbyState.hpp"

#include "../Views/LoadingScreenView.hpp"

#include "../Application.hpp"

#include <thread>
#include <iostream>

LoadingScreenState::LoadingScreenState(Application* app, TextureHolderPtr textures, Window& window, EventPoller* eventPoller)
    : m_app{app},
    iGameState(
            std::make_unique<LoadingScreenController>(eventPoller),
            std::make_unique<LoadingScreenView>(std::move(textures)),
            &window
        )
{
    m_view->init();
}

void LoadingScreenState::start(){
    TextureHolderPtr textureHolderPtr = std::make_unique<TextureHolder>();
    
    std::atomic<bool> flag{false};
    std::thread tMan( [this, &flag, &textureHolderPtr]{ 
        // load checkers textures
        initGameTextures(*textureHolderPtr);
        std::this_thread::sleep_for(std::chrono::seconds{1});
        flag = true;
    });

    while(m_window->isOpen() && flag == true){
        
        m_controller->handleEvents(*m_window);

        m_window->clear();

        m_view->render(*m_window);


        m_window->display();
    }

    tMan.join();
    // Add Game Controller.
    m_app->setState(std::make_unique<GameLobbyState>(m_app,m_view->stealTextures(),*m_window,m_controller->getEventPoller()));
}

void LoadingScreenState::initGameTextures(TextureHolder& textureHolder){
    textureHolder.load(TextureId::checkers_board,)
}
#include "LoadingScreenState.hpp"

#include <SFML/Graphics.hpp>


#include "../Controllers/iController.hpp"
#include "../Controllers/LoadingScreenController.hpp"

#include "GameLobbyState.hpp"

#include "../Views/LoadingScreenView.hpp"

#include "../Resources/PathStrings.hpp"

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
    TextureHolderPtr textures = std::make_unique<TextureHolder>();
    FontsHolderPtr fonts = std::make_unique<FontsHolder>();

    std::atomic<bool> flag{false};

    std::thread tMan([&]{ 
        std::this_thread::sleep_for(std::chrono::seconds{1});

        // load checkers textures
        textures->load(TextureId::checkers_black_white_cells, sBlackWhiteCellsPath);
        fonts->load(FontId::player_hud, sPlayerHudFont);
        flag = true;
    });

    while(m_window->isOpen() && flag == false){
        
        m_controller->handleEvents(*m_window);

        m_window->clear();

        m_view->render(*m_window);


        m_window->display();
    }

    tMan.join();
    // call nextState
    m_app->setState(std::make_unique<GameLobbyState>(m_app,std::move(textures), std::move(fonts), *m_window,m_controller->getEventPoller()));
}

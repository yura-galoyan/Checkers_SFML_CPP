#include "LoadingScreenState.hpp"

#include <SFML/Graphics.hpp>

#include <thread>

#include "../Controllers/iController.hpp"
#include "../Controllers/LoadingScreenController.hpp"

#include "GameLobbyState.hpp"

#include "../Views/LoadingScreenView.hpp"

#include "../Resources/PathStrings.hpp"

#include "../Application.hpp"

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
        std::this_thread::sleep_for(std::chrono::milliseconds{500});

        // load checkers textures
        textures->load(TextureId::checkers_black_white_cells, sBlackWhiteCellsPath);
        textures->load(TextureId::checkers_white_piece, sCheckersWhitePiece);
        textures->load(TextureId::checkers_black_piece, sCheckersBlackPiece);

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
    m_app->setState(std::make_unique<GameLobbyState>(m_app,std::move(textures), std::move(fonts), *m_window,m_controller->getEventPoller()));
    m_app->exec();
}

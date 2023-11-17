#include "LoadingScreenState.hpp"

#include <SFML/Graphics.hpp>
#include "GameLobbyState.hpp"


#include "../Controllers/GameLobbyController.hpp"

#include "../Controllers/iController.hpp"

#include "../Controllers/LoadingScreenController.hpp"
#include "../Views/LoadingScreenView.hpp"


#include "../Views/iView.hpp"


#include <thread>
#include <iostream>

LoadingScreenState::LoadingScreenState(Application* app, Window& window, Event& event)
    : m_app{app},
    iGameState(
            std::make_unique<LoadingScreenController>(window,event),
            std::make_unique<LoadingScreenView>()
        )
{
    m_view->init();
}


void LoadingScreenState::start( ){



    std::thread tMan([this]{ 
        std::this_thread::sleep_for(std::chrono::seconds{2});



    });

    while(m_controller->getWindow().isOpen()){
        
        m_controller->handleEvents();

        m_controller->getWindow().clear();

        m_view->render(m_controller->getWindow());

        m_controller->getWindow().display();
    }

    tMan.join();
    // Add Game Controller.
    m_app->setState(std::make_unique<GameLobbyState>(m_controller->getWindow(), m_controller->getEvent()));
}

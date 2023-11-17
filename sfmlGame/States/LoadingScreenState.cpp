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
    texManager.initLoadingScreenState();
    initSprite();
    animation = std::make_unique<AnimationHandler>(&sprite,sprite.getSize().x,sprite.getSize().y);
    animation->setDesiredFps(30);
    animation->setFrameCount(6);
    animation->setDelayBetweenFrames(0.1f);

}

void LoadingScreenState::start( ){


    std::thread tMan([this]{ 
        texManager.initGame();
        std::this_thread::sleep_for(std::chrono::duration<std::chrono::seconds>(1));
        finish();
    });

    sf::RectangleShape sh{{1600,900}};
    sh.setPosition({0,0});
    while(!isDone() && m_controller->getWindow().isOpen()){
        m_controller->queryEvents(m_window, m_event);
        
        m_window.clear();
        
        m_window.draw(sh);
        
        animation->playAnimation(AnimationHandler::Mode::REPEAT);
        
        draw(m_window);

        m_window.display();
    }

    tMan.join();
    // Add Game Controller.
    m_app->setState(std::make_unique<GameLobbyState>(m_controller->getWindow(), m_controller->getEvent()));
}

void LoadingScreenState::draw(Window& window){
    sprite.draw(window);
}

void LoadingScreenState::initSprite(){
    std::cout<<"Sprite initialized" <<std::endl;
    sprite.setStartingRect({1,1},{58,58});
    sprite.setTexture(&texManager["loading_screen"]);
    sprite.setPosition(0,0);
}

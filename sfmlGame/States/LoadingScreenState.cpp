#include "LoadingScreenState.hpp"

#include <SFML/Graphics.hpp>
#include "GameLobbyState.hpp"
#include <thread>
#include <iostream>

LoadingScreenState::LoadingScreenState(){
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
    while(!isDone() && m_window.isOpen()){
        m_controller.queryEvents(m_window, m_event);
        
        m_window.clear();
        
        m_window.draw(sh);
        
        animation->playAnimation(AnimationHandler::Mode::REPEAT);
        
        draw(m_window);

        m_window.display();
    }

    tMan.join();
    // Add Game Controller.
    m_app->setState(std::make_unique<GameLobbyState>(m_app,std::move(m_controller),m_window,m_event));
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

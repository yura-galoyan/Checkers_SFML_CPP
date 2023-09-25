#include "LoadingScreen.hpp"

#include <SFML/Graphics.hpp>

#include <thread>
#include <iostream>

LoadingScreen::LoadingScreen(){
    texManager.initLoadingScreen();
    initSprite();
    animation = std::make_unique<AnimationHandler>(&sprite,sprite.getSize().x,sprite.getSize().y);
    animation->setDesiredFps(30);
    animation->setFrameCount(6);
    animation->setDelayBetweenFrames(0.1f);

}

void LoadingScreen::start(Controller &controller, Window &window, Event &event){

    using namespace std::chrono_literals;

    std::thread tMan([this]{ 
        texManager.initGame();
        std::this_thread::sleep_for(1s);
        finish();
    });

    sf::RectangleShape sh{{1600,900}};
    while(!isDone() && window.isOpen()){
        controller.queryEvents(window, event);
        
        window.clear();
        
        sh.setPosition({0,0});
        window.draw(sh);
        
        animation->playAnimation(AnimationHandler::Mode::REPEAT);
        
        draw(window);

        window.display();
    }

    tMan.join();
}

void LoadingScreen::draw(Window& window){
    sprite.draw(window);
}

void LoadingScreen::initSprite(){
    std::cout<<"Sprite initialized" <<std::endl;
    sprite.setStartingRect({1,1},{58,58});
    sprite.setTexture(&texManager["loading_screen"]);
    sprite.setPosition(0,0);
}

#include "LoadingScreen.hpp"

#include <SFML/Graphics.hpp>

#include <thread>
#include <iostream>

LoadingScreen::LoadingScreen(){
    texManager.initLoadingScreen();
    initSprite();
    animation = std::make_unique<AnimationHandler>(&texManager["loading_screen"],60,60);
    animation->setDesiredFps(30);
    animation->setFrameCount(6);

}

void LoadingScreen::start(Controller &controller, Window &window, Event &event){

    using namespace std::chrono_literals;

    std::thread tMan([this]{ 
        texManager.initGame();
        std::this_thread::sleep_for(2s);
        finish();
    });

    while(!isDone()){
        controller.queryEvents(window, event);
        
        window.clear();
        
        sf::RectangleShape sh{{1600,900}};
        sh.setPosition({0,0});
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
    sprite.setRect({0,0},{60,60});
    sprite.setTexture(&texManager["loading_screen"]);
    sprite.setPosition(0,0);
}

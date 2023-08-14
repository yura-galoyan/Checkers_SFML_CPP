#include "LoadingScreen.hpp"

#include "Sprite.hpp"

#include <SFML/Graphics.hpp>

#include <thread>

#include <iostream>

void LoadingScreen::start(Controller& controller,Window& window,Event& event){
    
    using namespace std::chrono_literals;

    texManager.initLoadingScreen();
    initSprite();

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
        window.draw(sh);
        
        draw(window);

        window.display();
    }

    tMan.join();
}

void LoadingScreen::draw(Window& window){
    sprite.draw(window);
}

void LoadingScreen::initSprite(){
    std::cout<<"sprite inited" <<std::endl;
    sprite.setRect({0,0},{60,60});
    sprite.setTexture(&texManager["loading_screen"]);
    sprite.setPosition(0,0);
}

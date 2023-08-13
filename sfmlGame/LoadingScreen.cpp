#include "LoadingScreen.hpp"

#include "Sprite.hpp"

#include <thread>

void LoadingScreen::start(Controller& controller,Window& window,Event& event){
    
    using namespace std::chrono_literals;
    texManager.initLoadingScreen();
    initSprite();

    std::thread tMan([this]{ 
        texManager.initGame();
        std::this_thread::sleep_for(5s);
        finish();
    });

    while(!isDone()){
        window.clear();

        controller.queryEvents(window, event);
        draw(window);

        window.display();
    }

    tMan.join();
}

void LoadingScreen::draw(Window& window){
    sprite.draw(window);
}

void LoadingScreen::initSprite(){
    sprite.setRect({0,0},{60,60});
    sprite.setTexture(&texManager["loading_screen"]);
}

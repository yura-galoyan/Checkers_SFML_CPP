#include "LoadingScreen.hpp"

#include <thread>

void LoadingScreen::start(Controller& controller,Window& window,Event& event){
    
    using namespace std::chrono_literals;
    texManager.initLoadingScreen();
    

    std::thread tMan([this]{ 
        texManager.initGame();
        std::this_thread::sleep_for(5s);
        finish();
    });

    while(!isDone()){
        window.clear();

        controller.queryEvents(window, event);
        draw();

        window.display();
    }

    tMan.join();
}

void LoadingScreen::draw(){
    auto& tex = texManager["loading_screen"];

}

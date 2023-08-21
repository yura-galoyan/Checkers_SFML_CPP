#include "Controller.hpp"

#include <iostream>


void Controller::queryEvents(Window &window, Event &event){
    setFlags(window, event);

    if(mouseButtons['l'].state.pressedOnce){
        std::cout<<"pressed once left mouse button" << std::endl;
    }
    if(mouseButtons['l'].state.onHold){
        std::cout<<"holding right mouse button" << std::endl;
    }
    if(mouseButtons['l'].state.released){
        std::cout << "left mouse button released "  <<std::endl;
    }

}

void Controller::setFlags(Window &window, Event &event) { }
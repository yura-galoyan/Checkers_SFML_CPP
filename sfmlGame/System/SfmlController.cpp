#include "SfmlController.hpp"

#include "../CellSizeController.hpp"

SfmlController::SfmlController(){
    initMouseButtons();
    longReleasedTime = 0.05f;
}

#include <iostream>



bool SfmlController::setFlags(Window &window, Event &event){
    bool thereIsEvent{false};
    clearEvents();
    while(window.pollEvent(event)){
        switch (event.event().type)
        {
            case sf::Event::MouseButtonPressed:
                checkMouseButtonPressed(mouseButtons['l'], event);
                checkMouseButtonPressed(mouseButtons['r'], event);
                thereIsEvent = true;
                break;
            case sf::Event::MouseButtonReleased:
                checkMouseButtonReleased(mouseButtons['l'], event);
                checkMouseButtonReleased(mouseButtons['r'], event);
                thereIsEvent = true;
                break;
            case sf::Event::Closed:
                thereIsEvent = true;
                window.close();
                break;
            case sf::Event::Resized:
                thereIsEvent = true;
                CellSizeController::changeCellSizeTo(static_cast<int>(window.getSize().first / 8));
                window.setSize({window.getSize().first, window.getSize().first});
                break;
            default:
                break;
        }
    }
    return thereIsEvent;
}

void SfmlController::initMouseButtons(){
    mouseButtons['l'] = ButtonPair<char>{sf::Mouse::Button::Left,{}};
    mouseButtons['r'] = ButtonPair<char>{sf::Mouse::Button::Right,{}};
}

void SfmlController::checkMouseButtonPressed(ButtonPair<char>& buttonPair, Event &event){
    if(event.event().key.code == buttonPair.button){
        clockReleased.restart();
        buttonPair.state.clicked = true;
        buttonPair.state.onHold = true;
    }

}

void SfmlController::checkMouseButtonReleased(ButtonPair<char>& buttonPair, Event &event){
    if(event.event().key.code == buttonPair.button){
        if(clockReleased.elapsed() > longReleasedTime){
            buttonPair.state.longReleased = true;    
        }
        else{
            buttonPair.state.shortReleased = true;
        }
        buttonPair.state.onHold = false;
    }

}

void SfmlController::clearEvents(){
    for(auto& [key, mapped] : mouseButtons ){
        mapped.state.clicked = false;
        mapped.state.shortReleased = false;
        mapped.state.longReleased = false;
    }
}

auto SfmlController::atMouseButton(char button) -> ButtonPair<char> {
    return mouseButtons[button];
}

#include "SfmlController.hpp"

void SfmlController::queryEvents(Window& window, Event &event){

    clearEvents();
    while(window.pollEvent(event)){
        switch (event.event().type)
        {
            case sf::Event::MouseButtonPressed:
                checkMouseButtonPressed(mouseButtons['l'], event);
                checkMouseButtonPressed(mouseButtons['r'], event);
                break;
            case sf::Event::MouseButtonReleased:
                checkMouseButtonReleased(mouseButtons['l'], event);
                checkMouseButtonReleased(mouseButtons['r'], event);
            case sf::Event::MouseMoved:
                break;
        default:
            break;
        }
    }
}

void SfmlController::initMouseButtons(){
    mouseButtons['l'] = ButtonPair<sf::Mouse::Button>{sf::Mouse::Button::Left,{}};
    mouseButtons['r'] = ButtonPair<sf::Mouse::Button>{sf::Mouse::Button::Right,{}};
}

void SfmlController::checkMouseButtonPressed(ButtonPair<sf::Mouse::Button>& buttonPair, Event &event){
    if(event.event().key.code == buttonPair.button){
        buttonPair.state.pressedOnce = true;
        buttonPair.state.onHold = true;
    }

}

void SfmlController::checkMouseButtonReleased(ButtonPair<sf::Mouse::Button>& buttonPair, Event &event){
    if(event.event().key.code == buttonPair.button){
        buttonPair.state.released = true;
        buttonPair.state.onHold = false;
    }

}

void SfmlController::clearEvents(){
    for(auto& pair : mouseButtons ){
        pair.second.state.pressedOnce = false;
    }
}

auto SfmlController::atMouseButton(char button) -> ButtonPair<sf::Mouse::Button> {
    return mouseButtons[button];
}

#include "controller.hpp"

#include <iostream>

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::handleEvents(sf::Event& event, sf::RenderWindow& window){
    using Key = sf::Keyboard::Key;
    using Button = sf::Mouse::Button;

    clearPressedEvents();
    clearReleasedEvents();
    static int a = 0;
    while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed) {
            if(event.key.code == Key::W){
                keyboardEvents.w_key.pressed = true;
                keyboardEvents.w_key.onHold = true;
            }
            if(event.key.code == Key::A){

            }
            if(event.key.code == Key::S){
                
            }
            if(event.key.code == Key::D){
                
            }
        }
        if(event.type == sf::Event::MouseButtonPressed){
            if(event.key.code == Button::Left){
                keyboardEvents.mouseLeft.pressed = true;
                keyboardEvents.mouseLeft.onHold = true;
            }
            if(event.key.code == Button::Right){
                keyboardEvents.mouseRight.pressed = true;
                keyboardEvents.mouseRight.onHold = true;
            }
        }
        if(event.type == sf::Event::KeyReleased){
            if(event.key.code == Key::W){
                keyboardEvents.w_key.onHold = false;
                keyboardEvents.w_key.released = true;
            }
            if(event.key.code == Key::A){

            }
            if(event.key.code == Key::S){
                
            }
            if(event.key.code == Key::D){
                
            }
        }
        if(event.type == sf::Event::MouseButtonReleased){
            if(event.key.code == Button::Left){
                keyboardEvents.mouseLeft.onHold= false;
                keyboardEvents.mouseLeft.released = true;
            }
            if(event.key.code == Button::Right){
                keyboardEvents.mouseRight.onHold = false;
                keyboardEvents.mouseRight.released = true;
            }
        }
    }
};

void Controller::clearPressedEvents(){
    keyboardEvents.mouseLeft.pressed = false;
    keyboardEvents.mouseRight.pressed = false;
    keyboardEvents.w_key.pressed= false;
};

void Controller::clearReleasedEvents(){
    keyboardEvents.mouseLeft.released = false;
    keyboardEvents.mouseRight.released = false;
    keyboardEvents.w_key.released = false;

};
void Controller::initKeys(){

}
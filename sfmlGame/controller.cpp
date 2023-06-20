#include "controller.hpp"


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

    while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed) {
            if(event.key.code == Key::W){
                keyboardEvents.w_keyPressed = true;
                keyboardEvents.w_keyOnHold = true;
            }
            if(event.key.code == Key::A){

            }
            if(event.key.code == Key::S){
                
            }
            if(event.key.code == Key::D){
                
            }
            if(event.key.code == Button::Left){

            }
            if(event.key.code == Button::Right){

            }
        }
        if(event.type == sf::Event::KeyReleased){
            if(event.key.code == Key::W){
                keyboardEvents.w_keyOnHold = false;
            }
            if(event.key.code == Key::A){

            }
            if(event.key.code == Key::S){
                
            }
            if(event.key.code == Key::D){
                
            }
            if(event.key.code == Button::Left){
                keyboardEvents.mouseLeftButtonPressed = true;
                keyboardEvents.mouseLeftButtonOnHold = true;
            }
            if(event.key.code == Button::Right){
                keyboardEvents.mouseRightButtonPressed = true;
                keyboardEvents.mouseRightButtonOnHold = true;
            }
        }
    }

};

void Controller::clearPressedEvents(){
    keyboardEvents.mouseLeftButtonPressed = false;
    keyboardEvents.mouseRightButtonPressed = false;
    keyboardEvents.w_keyPressed = false;
};

void Controller::initKeys(){

}
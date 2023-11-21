#include "EventPoller.hpp"

#include "../Controllers/iController.hpp"

EventPoller::EventPoller(){
    initMouseButtons();
    longReleasedTime = 0.05f;
}

void EventPoller::setFlags(Window &window){
    Event event;
    bool thereIsEvent{false};
    clearEvents();
    while(window.pollEvent(event)){
        switch (event.event().type)
        {
            case sf::Event::MouseButtonPressed:
                checkMouseButtonPressed(m_mouseButtons['l'], event);
                checkMouseButtonPressed(m_mouseButtons['r'], event);
                break;
            case sf::Event::MouseButtonReleased:
                checkMouseButtonReleased(m_mouseButtons['l'], event);
                checkMouseButtonReleased(m_mouseButtons['r'], event);
                break;
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                // CellSizeController::changeCellSizeTo(static_cast<int>(window.getSize().first / 8));
                window.setSize({window.getSize().first, window.getSize().first});
                break;
            default:
                break;
        }
    }
}

void EventPoller::initMouseButtons(){
    m_mouseButtons['l'] = ButtonPair<char>{sf::Mouse::Button::Left,{}};
    m_mouseButtons['r'] = ButtonPair<char>{sf::Mouse::Button::Right,{}};
}

void EventPoller::checkMouseButtonPressed(ButtonPair<char>& buttonPair, Event &event){
    if(event.event().key.code == buttonPair.button){
        clockReleased.restart();
        buttonPair.state.clicked = true;
        leftMouseButtonClick();

        buttonPair.state.onHold = true;
    }

}

void EventPoller::leftMouseButtonClick(){
    m_controller->onLeftClickEvent();
}

void EventPoller::checkMouseButtonReleased(ButtonPair<char>& buttonPair, Event &event){
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

void EventPoller::clearEvents(){
    for(auto& [key, mapped] : m_mouseButtons ){
        mapped.state.clicked = false;
        mapped.state.shortReleased = false;
        mapped.state.longReleased = false;
    }
}

auto EventPoller::atMouseButton(char button) -> ButtonPair<char> {
    return m_mouseButtons[button];
}

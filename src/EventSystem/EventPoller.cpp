#include "EventPoller.hpp"

#include "../CellSizeController.hpp"
#include "../Controllers/iController.hpp"

EventPoller::EventPoller(){
    initMouseButtons();
    longReleasedTime = 0.05f;
}

void EventPoller::setFlags(Window &window){
    Event event;
    clearEvents();
    while(window.pollEvent(event)){
        switch (event.event().type)
        {
            case sf::Event::MouseButtonPressed:
                checkMouseButtonPressed(m_mouseButtons[Left], event);
                checkMouseButtonPressed(m_mouseButtons[Right], event);
                break;
            case sf::Event::MouseButtonReleased:
                checkMouseButtonReleased(m_mouseButtons[Left], event);
                checkMouseButtonReleased(m_mouseButtons[Right], event);
                break;
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
            {

                auto size = window.getSize();
                std::cout << "initial width: " <<  window.getStartWidth() << std::endl;
                std::cout << "now width: " <<  window.getSize().first << std::endl;
                auto initSize = std::make_pair(window.getStartWidth(),window.getStartWidth());



                CellSizeController::changeCellSizeTo(static_cast<int>(       110 / (static_cast<double>(initSize.first) / static_cast<double>(size.first)  )      ));
                window.setSize({window.getSize().first, window.getSize().first});
            }
                break;
            default:
                break;
        }
    }
}

void EventPoller::initMouseButtons(){
    m_mouseButtons[Left] = MouseButton(Left);
    m_mouseButtons[Right] = MouseButton(Right); 
}

void EventPoller::checkMouseButtonPressed(MouseButton& button, Event &event){
    if(event.event().key.code == button.data){
        clockReleased.restart();
        button.state.clicked = true;
        mouseButtonClick(button.data);

        button.state.onHold = true;
    }

}

void EventPoller::checkMouseButtonReleased(MouseButton& button, Event &event){
    if(event.event().key.code == button.data){
        if(clockReleased.elapsed() > longReleasedTime){
            button.state.longReleased = true;    
        }
        else{
            button.state.shortReleased = true;
        }
        button.state.onHold = false;
    }

}


void EventPoller::mouseButtonClick(MouseInput input){
    switch (input)
    {
    case Left:
        m_controller->onLeftClickEvent();
        break;
    case Right:
        m_controller->onRightClickEvent();
        break;
    default:
        break;
    }
    
}
void EventPoller::clearEvents(){
    for(auto& [key, mapped] : m_mouseButtons ){
        mapped.state.clicked = false;
        mapped.state.shortReleased = false;
        mapped.state.longReleased = false;
    }
}

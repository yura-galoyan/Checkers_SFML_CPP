#include "LoadingScreenController.hpp"

#include "../EventSystem/EventPoller.hpp"

#include <iostream>

LoadingScreenController::LoadingScreenController( EventPoller* eventPoller)
    : iController(eventPoller)
{

}

void LoadingScreenController::handleEvents(Window& window)
{
    m_eventPoller->setFlags(window);

}

void LoadingScreenController::onLeftClickEvent()
{
    std::cout << "left mouse button clicked" << std::endl;
}

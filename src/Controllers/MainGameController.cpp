#include "MainGameController.hpp"
#include "../EventSystem/EventPoller.hpp"
MainGameController::MainGameController(EventPoller* eventPoller)
    :iController(eventPoller)
{
}

void MainGameController::handleEvents(Window &window)
{
    m_eventPoller->setFlags(window);
}

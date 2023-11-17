#include "LoadingScreenController.hpp"



LoadingScreenController::LoadingScreenController( EventPoller* eventPoller)
    :iController(eventPoller)
{
}

void LoadingScreenController::handleEvents(Window& window)
{
    m_eventPoller->setFlags(window);



}

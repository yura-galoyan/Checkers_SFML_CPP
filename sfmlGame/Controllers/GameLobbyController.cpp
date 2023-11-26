#include "GameLobbyController.hpp"

#include "../EventSystem/EventPoller.hpp"

GameLobbyController::GameLobbyController(EventPoller* eventPoller)
    :iController(eventPoller)
{
}

void GameLobbyController::handleEvents(Window &window)
{
    m_eventPoller->setFlags(window);
}

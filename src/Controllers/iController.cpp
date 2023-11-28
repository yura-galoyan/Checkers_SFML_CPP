#include "iController.hpp"

#include "../EventSystem/EventPoller.hpp"

iController::iController(EventPoller *eventPoller)
    : m_eventPoller{eventPoller}
    {
        m_eventPoller->setController(this);
    }
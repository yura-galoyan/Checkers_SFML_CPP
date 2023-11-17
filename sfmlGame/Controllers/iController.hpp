#ifndef I_CONTROLLER_HPP
#define I_CONTROLLER_HPP


#include "../EventSystem/EventPoller.hpp"

class iController
{
public:
    iController(EventPoller* eventPoller)
        : m_eventPoller{eventPoller}
        {}
    
    auto getEventPoller(){ return m_eventPoller; }

    virtual void handleEvents(Window& window) = 0;

    auto* eventPoller() { return m_eventPoller; }

protected:
    EventPoller* m_eventPoller;
};


#endif //I_CONTROLLER_HPP
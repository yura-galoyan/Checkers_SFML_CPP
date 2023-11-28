#ifndef I_CONTROLLER_HPP
#define I_CONTROLLER_HPP

class EventPoller;
class Window;


class iController
{
public:
    iController(EventPoller* eventPoller); 
    ~iController() { } 
    auto getEventPoller(){ return m_eventPoller; }

    virtual void handleEvents(Window& window) = 0;
    virtual void onLoad(){};


    auto* eventPoller() { return m_eventPoller; }

    virtual void onLeftClickEvent(){};
    virtual void onLeftDoubleClickEvent(){};
    virtual void onRightClickEvent(){};
    virtual void onRightDoubleClickEvent(){};
    virtual void onLeftHoldEvent(){};
    virtual void onRightHoldEvent(){};
    virtual void onLeftMoveEvent(){};
    virtual void onRightMoveEvent(){};


protected:
    EventPoller* m_eventPoller;
};

#endif //I_CONTROLLER_HPP
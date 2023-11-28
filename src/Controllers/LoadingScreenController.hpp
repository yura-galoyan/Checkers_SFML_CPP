#ifndef CONTROLLERS_LOADING_SCREEN_CONTROLLER_HPP
#define CONTROLLERS_LOADING_SCREEN_CONTROLLER_HPP

#include "iController.hpp"

class LoadingScreenController : public iController
{
public:
    LoadingScreenController(EventPoller* eventPoller);

    void handleEvents(Window& window) override ;

    virtual void onLeftClickEvent();
    virtual void onLeftDoubleClickEvent(){};
    virtual void onRightClickEvent(){};
    virtual void onRightDoubleClickEvent(){};
    virtual void onLeftHoldEvent(){};
    virtual void onRightHoldEvent(){};
    virtual void onLeftMoveEvent(){};
    virtual void onRightMoveEvent(){};

};




#endif //CONTROLLERS_LOADING_SCREEN_CONTROLLER_HPP
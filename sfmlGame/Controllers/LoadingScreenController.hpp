#ifndef CONTROLLERS_LOADING_SCREEN_CONTROLLER_HPP
#define CONTROLLERS_LOADING_SCREEN_CONTROLLER_HPP

#include "iController.hpp"

class LoadingScreenController : public iController
{
public:
    LoadingScreenController(EventPoller* eventPoller);

    void handleEvents(Window& window) override ;

};


#endif //CONTROLLERS_LOADING_SCREEN_CONTROLLER_HPP
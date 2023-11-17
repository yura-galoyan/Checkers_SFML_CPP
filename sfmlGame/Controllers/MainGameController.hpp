#ifndef CONTROLLERS_MAIN_GAME_CONTROLLER_HPP
#define CONTROLLERS_MAIN_GAME_CONTROLLER_HPP

#include "iController.hpp"

class MainGameController : public iController
{
public:
    MainGameController(EventPoller* eventPoller);

    void handleEvents(Window& window) override;
};


#endif //CONTROLLERS_MAIN_GAME_CONTROLLER_HPP
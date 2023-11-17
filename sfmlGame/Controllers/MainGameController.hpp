#ifndef CONTROLLERS_MAIN_GAME_CONTROLLER_HPP
#define CONTROLLERS_MAIN_GAME_CONTROLLER_HPP

#include "iController.hpp"

class MainGameController : public iController
{
public:
    MainGameController(Window& window, Event& event);

    void handleEvents() override;
};


#endif //CONTROLLERS_MAIN_GAME_CONTROLLER_HPP
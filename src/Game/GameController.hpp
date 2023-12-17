#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

#include <unordered_map>
#include <string>

#include "Window.hpp"

#include "iController.hpp"

class GameController : public iController
{
public:
    GameController(Window& window, Event& event, AbstractBoardModel* model);
    void handleEvents() override; 
};


#endif //GAME_CONTROLLER_HPP

#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "Controller.hpp"
#include "System/Window.hpp"
#include "System/Event.hpp"

class GameState
{
public:
    virtual void start(Controller&, Window&, Event&) = 0;
};

#endif //GAME_STATE_HPP
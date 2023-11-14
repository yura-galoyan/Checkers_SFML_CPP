#ifndef STATES_I_GAME_STATE_HPP
#define STATES_I_GAME_STATE_HPP

#include <memory>

class iController;
class Application;

class iGameState
{
public:
    iGameState(std::unique_ptr<iController> controller) : m_controller(std::move(controller)) { }
    virtual void start() = 0;
    virtual void init(){};
    void changeState(Application* app, std::unique_ptr<iGameState> state) { app->setState(std::move(state)) };

protected:
    std::unique_ptr<iController> m_controller; 
};

/// I here, cause Application.hpp only forward declares iGameState class.
#include "../Application.hpp"

#endif //STATES_I_GAME_STATE_HPP
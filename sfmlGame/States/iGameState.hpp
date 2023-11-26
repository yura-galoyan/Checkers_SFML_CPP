#ifndef STATES_I_GAME_STATE_HPP
#define STATES_I_GAME_STATE_HPP

#include <memory>

#include "../EventSystem/EventPoller.hpp"

class iController;
class Application;
class Window;
class iView;


// LoadingScreenState, GameLobbyState, MainGameState... 
class iGameState
{
public:
    iGameState(std::unique_ptr<iController> controller, std::unique_ptr<iView> view, Window* window);
    ~iGameState();
    virtual void start() = 0;
    virtual void init(){};
    void changeState(Application* app, std::unique_ptr<iGameState> state);

protected:
    std::unique_ptr<iController> m_controller;
    std::unique_ptr<iView> m_view;
    Window* m_window;
};

/// I'll put it here for now, because Application.hpp only forward declares iGameState class.
#include "../Application.hpp"
#include "../Views/iView.hpp"

#endif //STATES_I_GAME_STATE_HPP
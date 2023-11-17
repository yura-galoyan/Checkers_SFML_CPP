#ifndef STATES_LOADING_SCREEN_STATE_HPP
#define STATES_LOADING_SCREEN_STATE_HPP

#include "iGameState.hpp"

#include "../System/Window.hpp"


class LoadingScreenState : public iGameState
{
public:
    LoadingScreenState(Application* app, Window& window, Event& event);

    void start() override;


private:
    Application* m_app;
};


#endif //STATES_LOADING_SCREEN_STATE_HPP
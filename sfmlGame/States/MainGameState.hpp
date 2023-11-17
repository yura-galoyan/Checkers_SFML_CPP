#ifndef STATES_MAIN_GAME_STATE_HPP
#define STATES_MAIN_GAME_STATE_HPP

#include "iGameState.hpp"

class MainGameState : public iGameState
{
public:
    MainGameState(Application* app,  TextureHolder textures, Window& window, EventPoller& eventPoller);

    
    void start() override;


private:
    Application* m_app;
};


#endif //STATES_MAIN_GAME_STATE_HPP
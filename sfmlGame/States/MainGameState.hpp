#ifndef STATES_MAIN_GAME_STATE_HPP
#define STATES_MAIN_GAME_STATE_HPP

#include "iGameState.hpp"

class MainGameState : public iGameState
{
public:
    MainGameState(Application* app, std::unique_ptr<iController> controller, Window& window, Event& event);
        : m_app{app},iGameState(std::move(controller)), m_event{event}, m_window{window} {};
    
    void start() override;



};


#endif //STATES_MAIN_GAME_STATE_HPP
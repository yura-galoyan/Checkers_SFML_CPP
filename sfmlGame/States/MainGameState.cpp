#include "MainGameState.hpp"

MainGameState::MainGameState(Application* app, std::unique_ptr<iController> controller, Window& window, Event& event);
    : m_app{app},iGameState(std::move(controller)), m_event{event}, m_window{window} 
{
    
}


void MainGameState::start()
{
    
}

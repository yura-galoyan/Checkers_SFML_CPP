#include "Application.hpp"

#include "Controllers/LoadingScreenController.hpp"
#include "States/LoadingScreenState.hpp"
#include "States/iGameState.hpp"
#include "Views/iView.hpp"



Application::Application(){
    m_window.create(1000,1000,"checkers");
    m_gameState = std::make_unique<LoadingScreenState>(this,std::make_unique<TextureHolder>(),m_window, &m_eventPoller);

}

int Application::exec()
{
    m_gameState->start(); 
    return 0;
}

void Application::setState(std::unique_ptr<iGameState> state)
{
    m_gameState = std::move(state);
}

Application::~Application()
{
}

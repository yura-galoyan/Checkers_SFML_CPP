#include "iGameState.hpp"

#include "../Controllers/iController.hpp"

iGameState::iGameState(std::unique_ptr<iController> controller, std::unique_ptr<iView> view, Window *window): 
        m_controller(std::move(controller)),
        m_view{std::move(view)},
        m_window{window}
{
}

iGameState::~iGameState(){ }

void iGameState::changeState(Application *app, std::unique_ptr<iGameState> state)
{
    app->setState(std::move(state));
};
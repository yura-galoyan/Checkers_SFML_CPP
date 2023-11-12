#include "iController.hpp"

iController::iController(Window& window, Event& event, AbstractBoardModel* model)
    :m_window{window}, m_event(event),m_model{model}
{
}
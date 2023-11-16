#ifndef I_CONTROLLER_HPP
#define I_CONTROLLER_HPP

#include "System/Window.hpp"
#include "System/Event.hpp"
#include "ChessJudge.hpp"

class AbstractBoardModel;

class iController
{
public:
    iController(Window& window, Event& event);

    virtual void handleEvents() = 0;

protected:
    Window& m_window;
    Event& m_event;
};


#endif //I_CONTROLLER_HPP
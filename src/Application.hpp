#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "EventSystem/EventPoller.hpp"

#include <memory>

#include "States/iGameState.hpp"

class Application
{
public:
    Application();
    int exec();
    void setState(std::unique_ptr<iGameState> state);

    /// INFO:
    //  without destructor you can't create unique_ptr on incomplete type, kinda
    ~Application();

private:
    std::unique_ptr<iGameState> m_gameState;    
    Window m_window;
    EventPoller m_eventPoller;
};

#endif //APPLICATION_HPP
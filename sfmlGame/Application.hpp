#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "EventPoller.hpp"

class iGameState;

class Application
{
public:
    Application();
    int exec();
    void setState(std::unique_ptr<iGameState> state);

private:
    std::unique_ptr<iGameState> m_gameState;
    // EventPoller poller;
    Window window;
    Event event;

};

#endif //APPLICATION_HPP
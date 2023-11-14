#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "EventPoller.hpp"

class iGameState;

class Application
{
public:
    Application();
    int exec();
    void setState(std::unique_ptr<GameState> state);

private:
    std::unique_ptr<iGameState> m_gameState;
    // LoadingScreen loadingScreen;
    // EventPoller poller;
    Window window;
    Event event;
    // Game game;
};

#endif //APPLICATION_HPP
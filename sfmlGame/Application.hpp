#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "EventPoller.hpp"

#include "System/Controller.hpp"
#include "LoadingScreen.hpp"
#include "System/Window.hpp"
#include "Game.hpp"

class Application
{
public:
    Application();
    int exec();

private:
    LoadingScreen loadingScreen;
    EventPoller poller;
    Window window;
    Event event;
    Game game;
};

#endif //APPLICATION_HPP
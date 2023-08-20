#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Game.hpp"

class Application
{

public:
    Application();
    void execute();

private:
    Game game;
    LoadingScreen loadingScreen;
};


#endif //APPLICATION_HPP
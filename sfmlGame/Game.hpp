#ifndef GAME_HPP
#define GAME_HPP



#include "Factories/AbstractSystemFactory.hpp"
#include "Factories/PieceAbstractFactory.hpp"
#include "AbstractBoardModel.hpp"
#include "AbstractBoardView.hpp"
#include "LoadingScreen.hpp"
#include "System/Controller.hpp"
#include "System/Window.hpp"
#include "BackGround.hpp"

#include <memory>

class Game
{
public:
    Game() = default;
    Game(std::unique_ptr<Window> window);
    
    void start();

public:
    void createBoard(std::unique_ptr<PieceAbstractFactory> factory, std::unique_ptr<AbstractSystemFactory> systemFactory);
    void setWindow(std::unique_ptr<Window> window);
    void setView(AbstractBoardView boardView);
    void setController(Controller controller);


private:
    std::unique_ptr<AbstractBoardView> boardView;
    std::unique_ptr<Controller> controller;
    std::unique_ptr<Window> window;
    LoadingScreen loadingScreen;
    BackGround backGround;
    Event event;
};

#endif //GAME_HPP
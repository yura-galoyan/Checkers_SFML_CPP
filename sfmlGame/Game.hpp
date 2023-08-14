#ifndef GAME_HPP
#define GAME_HPP


#include "Factories/ChessAbstractFactory.hpp"
#include "AbstractBoardModel.hpp"
#include "AbstractBoardView.hpp"
#include "LoadingScreen.hpp"
#include "Controller.hpp"
#include "BackGround.hpp"
#include "Window.hpp"

#include <memory>

class Game
{
public:
    Game() = default;
    Game(unsigned height, unsigned width, std::string title);
    
    void start();

public:
    std::unique_ptr<AbstractBoardModel> createBoard(std::unique_ptr<ChessAbstractFactory> factory);
    void setView(AbstractBoardView* boardView);
    void setController(Controller* controller);

    void loadTextures();

private:
    AbstractBoardView* boardView;
    Controller* controller;
    LoadingScreen loadingScreen;
    BackGround backGround;
    Window window;
    Event event;
};

#endif //GAME_HPP
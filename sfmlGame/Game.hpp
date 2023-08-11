#ifndef GAME_HPP
#define GAME_HPP


#include "Factories/ChessAbstractFactory.hpp"
#include "AbstractBoardModel.hpp"
#include "AbstractBoardView.hpp"
#include "Controller.hpp"
#include "BackGround.hpp"
#include "Window.hpp"

#include <memory>

class Game
{
public:
    Game() = default;
    void start();

public:
    std::unique_ptr<AbstractBoardModel> createBoard(std::unique_ptr<ChessAbstractFactory> factory);
    void setView(AbstractBoardView* boardView);
    void setController(Controller* controller);


private:
    AbstractBoardView* boardView;
    Controller* controller;
    BackGround backGround;
    Window window;
    Event event;
};

#endif //GAME_HPP
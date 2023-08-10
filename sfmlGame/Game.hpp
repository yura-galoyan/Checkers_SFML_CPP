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
    void handleEvents();

public:
    std::unique_ptr<AbstractBoardModel> createBoard(std::unique_ptr<ChessAbstractFactory> factory);
    void setView(AbstractBoardView* boardView);



private:
    AbstractBoardView* boardView;
    BackGround backGround;
    Controller controller;
    Window window;
    Event event;
};

#endif //GAME_HPP
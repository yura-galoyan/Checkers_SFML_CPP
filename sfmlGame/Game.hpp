#ifndef GAME_HPP
#define GAME_HPP


#include "Factories/ChessAbstractFactory.hpp"
#include "AbstractBoardModel.hpp"
#include "AbstractBoardView.hpp"
#include "BackGround.hpp"
#include "Event.hpp"

#include <memory>

class Game
{
public:
    void start();
    void handleEvents();

public:
    std::unique_ptr<AbstractBoardModel> createBoard(std::unique_ptr<ChessAbstractFactory> factory);
    void setView(AbstractBoardView* boardView);



private:
    AbstractBoardView* boardView;
    BackGround backGround;
    Event event;
};

#endif //GAME_HPP
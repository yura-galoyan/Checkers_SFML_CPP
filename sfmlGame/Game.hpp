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
    Game(unsigned height, unsigned width, std::string title);
    
    void start();

public:
    void createBoard(std::unique_ptr<PieceAbstractFactory> factory, std::unique_ptr<AbstractSystemFactory> systemFactory);

private:
    void createPieces(AbstractBoardModel* model, std::unique_ptr<PieceAbstractFactory> factory);
    void initPiece(Piece* piece, int x, int sizeX = 58, int sizeY = 110 );

private:
    int size;
    bool onceFlag{true};

private:
    std::unique_ptr<AbstractBoardView> boardView;
    std::unique_ptr<Controller> controller;
    LoadingScreen loadingScreen;
    BackGround backGround;
    Window window;
    Event event;
};

#endif //GAME_HPP
#if FALSE

#ifndef GAME_HPP
#define GAME_HPP



#include "Factories/AbstractSystemFactory.hpp"
#include "Factories/PieceAbstractFactory.hpp"
#include "AbstractBoardModel.hpp"
#include "AbstractBoardView.hpp"
#include "BackGround.hpp"
#include "Ynet/Client.hpp"
#include "Common.hpp"

#include <memory>



class Game : Ynet::ClientInterface<ChessMsgTypes>
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
    void queryNetwork();

private:
    int size;
    bool onceFlag{true};

private:
    Player player{0,Color::None};

private:
    std::unique_ptr<AbstractBoardView> boardView;
    BackGround backGround;
};

#endif //GAME_HPP

#endif
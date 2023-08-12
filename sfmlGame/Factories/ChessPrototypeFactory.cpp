#include "ChessPrototypeFactory.hpp"

ChessPrototypeFactory::ChessPrototypeFactory(PiecePtr<Pawn> pawn, PiecePtr<Queen> queen, PiecePtr<Rook> rook,
                                             PiecePtr<Knight> knight, PiecePtr<Bishop> bishop, PiecePtr<King> king,
                                             std::unique_ptr<AbstractBoardModel> board )
   :pawnPrototype(std::move(pawn)),
    queenPrototype(std::move(queen)),
    kingPrototype(std::move(king)),
    rookPrototype(std::move(rook)),
    knightPrototype(std::move(knight)),
    bishopPrototype(std::move(bishop)),
    boardPrototype(std::move(board))
{

}

auto ChessPrototypeFactory::makePawn() -> PiecePtr<>
{
    static std::size_t x{0};

    PiecePtr<Piece> pawn = pawnPrototype->clone();

    if( x < 8){
        pawn->setXY({x++,1});
        pawn->setColor(Piece::Color::Black);
    }
    else{
        pawn->setXY({(x++)%8,6});
        pawn->setColor(Piece::Color::White);
    }

    return pawn;
}

auto ChessPrototypeFactory::makeQueen() -> PiecePtr<>
{

    PiecePtr<Piece> queen = queenPrototype->clone();
    queen->setPosition(3);
    return queen;
}

auto ChessPrototypeFactory::makeKing() -> PiecePtr<>
{
    PiecePtr<Piece> king = kingPrototype->clone();
    king->setPosition(4);
    return king;
}
#include <iostream>

auto ChessPrototypeFactory::makeKnight() -> PiecePtr<>
{
    PiecePtr<Piece> knight = knightPrototype->clone();
    static int twice{};
    if(twice++ < 2){
        knight->setPosition(1);
    }
    else{
        knight->setPosition(6);
    }
    return knight;
}

auto ChessPrototypeFactory::makebishop() -> PiecePtr<>
{
    PiecePtr<Piece> bishop = bishopPrototype->clone();
    static int twice{};
    if(twice++ < 2){
        bishop->setPosition(2);
    }
    else{
        bishop->setPosition(5);
    }
    return bishop;
}

auto ChessPrototypeFactory::makeRook() -> PiecePtr<>
{
    PiecePtr<Piece> rook = rookPrototype->clone();
    static int twice{};
    if(twice++ < 2){
        rook->setPosition(0);
    }
    else{
        rook->setPosition(7);
    }
    return rook;
}

auto ChessPrototypeFactory::makeBoard() -> std::unique_ptr<AbstractBoardModel>
{
    return boardPrototype->clone();
}

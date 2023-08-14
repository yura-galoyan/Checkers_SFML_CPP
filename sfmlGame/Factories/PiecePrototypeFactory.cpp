#include "PiecePrototypeFactory.hpp"

PiecePrototypeFactory::PiecePrototypeFactory(PiecePtr<Pawn> pawn, PiecePtr<Queen> queen, PiecePtr<Rook> rook,
                                             PiecePtr<Knight> knight, PiecePtr<Bishop> bishop, PiecePtr<King> king )
   :pawnPrototype(std::move(pawn)),
    queenPrototype(std::move(queen)),
    kingPrototype(std::move(king)),
    rookPrototype(std::move(rook)),
    knightPrototype(std::move(knight)),
    bishopPrototype(std::move(bishop))
{

}

auto PiecePrototypeFactory::makePawn() -> PiecePtr<> {
    static std::size_t x{0};

    PiecePtr<Piece> pawn = pawnPrototype->clone();

    pawn->setSprite(Sprite{ {0,0}, {64,131}});
    
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

auto PiecePrototypeFactory::makeQueen() -> PiecePtr<> {

    PiecePtr<Piece> queen = queenPrototype->clone();
    queen->setSprite({ {256,0}, {64,131}});
    queen->setPosition(3);
    return queen;
}

auto PiecePrototypeFactory::makeKing() -> PiecePtr<> {
    PiecePtr<Piece> king = kingPrototype->clone();
    king->setSprite({{320,0}, {64,131}});
    king->setPosition(4);
    return king;
}
#include <iostream>

auto PiecePrototypeFactory::makeKnight() -> PiecePtr<> {
    PiecePtr<Piece> knight = knightPrototype->clone();
    static int twice{};
    knight->setSprite({{64,0}, {64,131}});
    if(twice++ < 2){
        knight->setPosition(1);
    }
    else{
        knight->setPosition(6);
    }
    return knight;
}

auto PiecePrototypeFactory::makebishop() -> PiecePtr<> {
    PiecePtr<Piece> bishop = bishopPrototype->clone();
    static int twice{};
    bishop->setSprite({{192,0}, {64,131}});
    if(twice++ < 2){
        bishop->setPosition(2);
    }
    else{
        bishop->setPosition(5);
    }
    return bishop;
}

auto PiecePrototypeFactory::makeRook() -> PiecePtr<> {
    PiecePtr<Piece> rook = rookPrototype->clone();
    static int twice{};
    rook->setSprite({{128,0}, {64,131}});
    if(twice++ < 2){
        rook->setPosition(0);
    }
    else{
        rook->setPosition(7);
    }
    return rook;
}

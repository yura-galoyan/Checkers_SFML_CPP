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

    Sprite sprite;
    if( x < 8){
        int place = 1;
        pawn->setXY({x,place});
        sprite.setPosition(x++ * 110 + 1 + 20, place * 110  );
        pawn->setColor(Piece::Color::Black);
    }
    else{
        int place = 6;
        pawn->setXY({(x)%8,place});
        sprite.setPosition((x++%8) * 110 + 1 + 20,place * 110 );
        pawn->setColor(Piece::Color::White);
    }

    pawn->setSprite(sprite);
    return pawn;
}

auto PiecePrototypeFactory::makeQueen() -> PiecePtr<> {

    PiecePtr<Piece> queen = queenPrototype->clone();
    Sprite sprite;
    sprite.setPosition(3 * 110 +1 + 20,0 * 110 );
    queen->setSprite( sprite);
    queen->setPosition(3);
    return queen;
}

auto PiecePrototypeFactory::makeKing() -> PiecePtr<> {
    PiecePtr<Piece> king = kingPrototype->clone();

    Sprite sprite;
    sprite.setPosition(4 * 110 +1 + 20,0 * 110 );
    king->setSprite(sprite);
    king->setPosition(4);
    return king;
}

auto PiecePrototypeFactory::makeKnight() -> PiecePtr<> {
    PiecePtr<Piece> knight = knightPrototype->clone();
    static int twice{};
    Sprite sprite;
    if(twice++ < 2){
        sprite.setPosition(1 * 110 + 1 + 20,0 * 110 );
        knight->setSprite(sprite);
        knight->setPosition(1);
    }
    else{
        sprite.setPosition(6 * 110 + 1 + 20,0 * 110 );
        knight->setSprite(sprite);
        knight->setPosition(6);
    }
    return knight;
}

auto PiecePrototypeFactory::makeBishop() -> PiecePtr<> {
    PiecePtr<Piece> bishop = bishopPrototype->clone();
    static int twice{};

    Sprite sprite;

    if(twice++ < 2){
        sprite.setPosition(2 * 110 + 1 + 20,0 * 110 );
        bishop->setSprite(sprite);
        bishop->setPosition(2);
    }
    else{
        sprite.setPosition(5 * 110 + 1 + 20,0 * 110 );
        bishop->setSprite(sprite);
        bishop->setPosition(5);
    }
    return bishop;
}

auto PiecePrototypeFactory::makeRook() -> PiecePtr<> {
    PiecePtr<Piece> rook = rookPrototype->clone();
    static int twice{};

    Sprite sprite;

    if(twice++ < 2){
        sprite.setPosition(0 * 110 + 1 + 20,0 * 110 );
        rook->setSprite(sprite);
        rook->setPosition(0);
    }
    else{
        sprite.setPosition(7 * 110 + 1 + 20,0 * 110 );
        rook->setSprite(sprite);
        rook->setPosition(7);
    }
    return rook;
}

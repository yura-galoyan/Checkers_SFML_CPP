#ifndef PIECE_PROTOTYPE_FACTORY_HPP
#define PIECE_PROTOTYPE_FACTORY_HPP

#include <memory>

#include "../Pieces/King.hpp"
#include "../Pieces/Queen.hpp"
#include "../Pieces/Pawn.hpp"
#include "../Pieces/Knight.hpp"
#include "../Pieces/Rook.hpp"
#include "../Pieces/Bishop.hpp"


#include "PieceAbstractFactory.hpp"


class PiecePrototypeFactory : public PieceAbstractFactory
{
public:
    PiecePrototypeFactory() = default;
    PiecePrototypeFactory(PiecePtr<Pawn> pawn, PiecePtr<Queen> queen, PiecePtr<Rook> rook,
                          PiecePtr<Knight> knight, PiecePtr<Bishop> bishop, PiecePtr<King> king );


    virtual PiecePtr<> makePawn() override;
    virtual PiecePtr<> makeQueen() override;
    virtual PiecePtr<> makeKing() override;
    virtual PiecePtr<> makeKnight() override;
    virtual PiecePtr<> makeBishop() override;
    virtual PiecePtr<> makeRook() override;
    
private:
    PiecePtr<> pawnPrototype;
    PiecePtr<> queenPrototype;
    PiecePtr<> kingPrototype;
    PiecePtr<> rookPrototype;
    PiecePtr<> knightPrototype;
    PiecePtr<> bishopPrototype;
};

#endif //PIECE_PROTOTYPE_FACTORY_HPP


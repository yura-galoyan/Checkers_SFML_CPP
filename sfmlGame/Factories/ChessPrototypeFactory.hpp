#ifndef PIECE_PROTOTYPE_FACTORY_HPP
#define PIECE_PROTOTYPE_FACTORY_HPP

#include <memory>

#include "../Pieces/King.hpp"
#include "../Pieces/Queen.hpp"
#include "../Pieces/Pawn.hpp"
#include "../Pieces/Knight.hpp"
#include "../Pieces/Rook.hpp"
#include "../Pieces/Bishop.hpp"


#include "ChessAbstractFactory.hpp"


class ChessPrototypeFactory : public ChessAbstractFactory
{
public:
    ChessPrototypeFactory() = default;
    ChessPrototypeFactory(PiecePtr<Pawn> pawn, PiecePtr<Queen> queen, PiecePtr<Rook> rook,
                          PiecePtr<Knight> knight, PiecePtr<Bishop> bishop, PiecePtr<King> king,
                          std::unique_ptr<AbstractBoardModel> board );


    virtual PiecePtr<> makePawn() override;
    virtual PiecePtr<> makeQueen() override;
    virtual PiecePtr<> makeKing() override;
    virtual PiecePtr<> makeKnight() override;
    virtual PiecePtr<> makebishop() override;
    virtual PiecePtr<> makeRook() override;
    virtual std::unique_ptr<AbstractBoardModel> makeBoard() override;
    
private:
    PiecePtr<> pawnPrototype;
    PiecePtr<> queenPrototype;
    PiecePtr<> kingPrototype;
    PiecePtr<> rookPrototype;
    PiecePtr<> knightPrototype;
    PiecePtr<> bishopPrototype;
    std::unique_ptr<AbstractBoardModel> boardPrototype;
};

#endif //PIECE_PROTOTYPE_FACTORY_HPP


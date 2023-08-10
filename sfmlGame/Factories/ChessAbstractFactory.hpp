#ifndef CHESS_ABSTRACT_FACTORY_HPP
#define CHESS_ABSTRACT_FACTORY_HPP


#include "../AbstractBoardModel.hpp"

#include <memory>

class ChessAbstractFactory
{
public:
    template<typename T = Piece>
    using PiecePtr = std::unique_ptr<T>;

public:
    virtual ~ChessAbstractFactory() { }

    virtual PiecePtr<> makePawn() = 0;
    virtual PiecePtr<> makeQueen() = 0;
    virtual PiecePtr<> makeKing() = 0;
    virtual PiecePtr<> makeKnight() = 0;
    virtual PiecePtr<> makebishop() = 0;
    virtual PiecePtr<> makeRook() = 0;
    virtual std::unique_ptr<AbstractBoardModel> makeBoard() = 0;
};

#endif //CHESS_ABSTRACT_FACTORY_HPP


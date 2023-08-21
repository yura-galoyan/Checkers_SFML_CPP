#ifndef CHESS_ABSTRACT_FACTORY_HPP
#define CHESS_ABSTRACT_FACTORY_HPP



#include <memory>

class PieceAbstractFactory
{
public:
    template<typename T = Piece>
    using PiecePtr = std::unique_ptr<T>;

public:
    virtual ~PieceAbstractFactory() { }

    virtual PiecePtr<> makePawn() = 0;
    virtual PiecePtr<> makeQueen() = 0;
    virtual PiecePtr<> makeKing() = 0;
    virtual PiecePtr<> makeKnight() = 0;
    virtual PiecePtr<> makeBishop() = 0;
    virtual PiecePtr<> makeRook() = 0;
};

#endif //CHESS_ABSTRACT_FACTORY_HPP


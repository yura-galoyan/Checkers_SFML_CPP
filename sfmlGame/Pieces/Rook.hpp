#ifndef ROOK_HPP
#define ROOK_HPP

#include "Piece.hpp"

class Rook : public Piece
{
public:
    Rook() = default;
    Rook(const Rook& q){}
    virtual std::unique_ptr<Piece> clone() const override ;
    virtual void move(Coords xy) override ;
    virtual void draw(Window& window) override ;
};


#endif //ROOK_HPP
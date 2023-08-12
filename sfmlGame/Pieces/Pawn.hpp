#ifndef PAWN_HPP
#define PAWN_HPP

#include "Piece.hpp"

class Pawn : public Piece 
{
public:
    Pawn() = default;
    Pawn(const Pawn& q){}
    virtual std::unique_ptr<Piece> clone() const override;
    virtual void move(Coords xy) override ;
    virtual void draw(Window& window) override ;
};

#endif //PAWN_HPP
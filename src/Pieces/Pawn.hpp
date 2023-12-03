#ifndef PAWN_HPP
#define PAWN_HPP

#include "Piece.hpp"

class Pawn : public Piece 
{
public:
    Pawn() = default;
    Pawn(const Pawn& q){}
    std::unique_ptr<Piece> clone() const override;
    bool isValid(Coords from, Coords to) const override;
    void draw(Window& window) override ;
    void draw(Window& window, Vector2f position) override;

};

#endif //PAWN_HPP
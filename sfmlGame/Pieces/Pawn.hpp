#ifndef PAWN_HPP
#define PAWN_HPP

#include "Piece.hpp"

class Pawn : public Piece 
{
public:
    Pawn() = default;
    Pawn(const Pawn& q){}
    std::unique_ptr<Piece> clone() const override;
    void moveTo(Coords xy) override ;
    void draw(Window& window, Texture& texture) override ;

};

#endif //PAWN_HPP
#include "Pawn.hpp"

#include <iostream>

std::unique_ptr<Piece> Pawn::clone() const
{
    return std::make_unique<Pawn>(*this);
}

bool Pawn::isValid(Coords from, Coords to) const{
    return true;
}


void Pawn::draw(Window& window){
    sprite.draw(window); 
}

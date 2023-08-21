#include "Pawn.hpp"

std::unique_ptr<Piece> Pawn::clone() const
{
    return std::make_unique<Pawn>(*this);
}

void Pawn::moveTo(Coords xy)
{
}

void Pawn::draw(Window &window, Texture& texture){
    

    sprite.draw(window); 
    
}

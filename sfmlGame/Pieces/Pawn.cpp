#include "Pawn.hpp"

std::unique_ptr<Piece> Pawn::clone() const
{
    return std::make_unique<Pawn>(*this);
}

void Pawn::moveTo(Coords xy)
{
}

void Pawn::draw(Window &window, Texture& texture){
    
    if(!isStarted()){

        if(getColor() == Color::White){
            sprite.setStartingRect({1,1},{58,110});
        }
        else if(getColor() == Color::Black){
            sprite.setStartingRect({1,112},{58,110});
        }

        sprite.setTexture(&texture);
        setStarted(true);
    }
    sprite.draw(window); 
    
}

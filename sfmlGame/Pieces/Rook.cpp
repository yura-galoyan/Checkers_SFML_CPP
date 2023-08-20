#include "Rook.hpp"

std::unique_ptr<Piece> Rook::clone() const
{
    return std::make_unique<Rook>(*this);
}

void Rook::moveTo(Coords xy){
    
}

void Rook::draw(Window& window, Texture& texture){
   
    if(!isStarted()){
        if(getColor() == Color::White){
            sprite.setStartingRect({1 + 60 * 2, 1},{58,110});
        }
        else if(getColor() == Color::Black){
            sprite.setStartingRect({1 + 60 * 2, 112},{58,110});
        }

        sprite.setTexture(&texture);
        setStarted(true);
    }
    sprite.draw(window);   

}

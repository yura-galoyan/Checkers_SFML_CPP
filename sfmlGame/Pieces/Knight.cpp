#include "Knight.hpp"

std::unique_ptr<Piece> Knight::clone() const
{
    return std::make_unique<Knight>(*this);
}

void Knight::moveTo(Coords xy){
    
}

void Knight::draw(Window & window, Texture& texture ){
    if(!isStarted()){
        if(getColor() == Color::White){
            sprite.setStartingRect({1 + 60 * 1, 1},{58,110});
        }
        else if(getColor() == Color::Black){
            sprite.setStartingRect({1 + 60 * 1, 112},{58,110});
        }

        sprite.setTexture(&texture);
        setStarted(true);
    }
    sprite.draw(window);   

}

#include "King.hpp"

std::unique_ptr<Piece> King::clone() const
{
    return std::make_unique<King>(*this);
}

void King::moveTo(Coords xy)
{
}

void King::draw(Window& window, Texture& texture){
    if(!isStarted()){

        if(getColor() == Color::White){
            sprite.setStartingRect({1 + 60 * 5, 1},{58,110});
        }
        else if(getColor() == Color::Black){
            sprite.setStartingRect({1 + 60 * 5, 112},{58,110});
        }

        sprite.setTexture(&texture);
        setStarted(true);
    }
    sprite.draw(window);   

}

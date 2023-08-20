#include "Bishop.hpp"

std::unique_ptr<Piece> Bishop::clone() const
{
    return std::make_unique<Bishop>(*this);
}

void Bishop::moveTo(Coords xy)
{
}

void Bishop::draw(Window& window, Texture& texture){
    if(!isStarted()){

        if(getColor() == Color::White){
            sprite.setStartingRect({1 + 60 * 3, 1},{58,110});
        }
        else if(getColor() == Color::Black){
            sprite.setStartingRect({1 + 60 * 3, 112},{58,110});
        }

        sprite.setTexture(&texture);
        setStarted(true);
    }
    sprite.draw(window);   

}

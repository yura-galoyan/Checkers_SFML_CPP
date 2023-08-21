#include "Bishop.hpp"

std::unique_ptr<Piece> Bishop::clone() const
{
    return std::make_unique<Bishop>(*this);
}

void Bishop::moveTo(Coords xy)
{
}

void Bishop::draw(Window& window, Texture& texture){
    
    sprite.draw(window);   

}

#include "King.hpp"

std::unique_ptr<Piece> King::clone() const
{
    return std::make_unique<King>(*this);
}

void King::move(Coords xy)
{
}

void King::draw(Window& window, Texture& texture){
    
}

#include "King.hpp"

std::unique_ptr<Piece> King::clone() const
{
    return std::make_unique<King>(*this);
}

bool King::isValid(Coords from, Coords to) const {
    return true;
}

void King::draw(Window& window){
    sprite.draw(window);   
}

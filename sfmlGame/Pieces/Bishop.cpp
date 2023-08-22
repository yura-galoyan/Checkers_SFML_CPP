#include "Bishop.hpp"

std::unique_ptr<Piece> Bishop::clone() const {
    return std::make_unique<Bishop>(*this);
}

bool Bishop::isValid(Coords from, Coords to) const {
    return true;
}

void Bishop::draw(Window& window){
    sprite.draw(window);   
}

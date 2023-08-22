#include "Rook.hpp"

std::unique_ptr<Piece> Rook::clone() const
{
    return std::make_unique<Rook>(*this);
}

bool Rook::isValid(Coords from, Coords to) const{
    return true;
}

void Rook::draw(Window& window){
    sprite.draw(window);   
}

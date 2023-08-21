#include "Rook.hpp"

std::unique_ptr<Piece> Rook::clone() const
{
    return std::make_unique<Rook>(*this);
}

void Rook::moveTo(Coords xy){
    
}

void Rook::draw(Window& window, Texture& texture){
    sprite.draw(window);   
}

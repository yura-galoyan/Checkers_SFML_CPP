#include "Rook.hpp"

std::unique_ptr<Piece> Rook::clone() const
{
    return std::make_unique<Rook>(*this);
}

void Rook::move(Coords xy){
    
}

void Rook::draw(Window &window){
    
}

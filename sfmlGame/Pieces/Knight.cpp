#include "Knight.hpp"

std::unique_ptr<Piece> Knight::clone() const
{
    return std::make_unique<Knight>(*this);
}

void Knight::move(Coords xy){
    
}

void Knight::draw(Window & window, Texture & texture){
    
}

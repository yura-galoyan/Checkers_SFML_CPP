#include "Queen.hpp"

std::unique_ptr<Piece> Queen::clone() const
{
    return std::make_unique<Queen>(*this);
}

void Queen::move(Coords xy){
    
}

void Queen::draw(Window& window){
    
}

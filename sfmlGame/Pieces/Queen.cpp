#include "Queen.hpp"

std::unique_ptr<Piece> Queen::clone() const
{
    return std::make_unique<Queen>(*this);
}

bool Queen::isValid(Coords from, Coords to) const {
    return true;
};

void Queen::draw(Window& window){
    sprite.draw(window);   
}

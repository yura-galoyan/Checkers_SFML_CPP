#include "Knight.hpp"

std::unique_ptr<Piece> Knight::clone() const
{
    return std::make_unique<Knight>(*this);
}

bool Knight::isValid(Coords from, Coords to) const{
    return true;
}

void Knight::draw(Window& window ){

    sprite.draw(window);   

}

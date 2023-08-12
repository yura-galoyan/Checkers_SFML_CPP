#include "Bishop.hpp"

std::unique_ptr<Piece> Bishop::clone() const
{
    return std::make_unique<Bishop>(*this);
}

void Bishop::move(Coords xy)
{
}

void Bishop::draw(Window &window)
{
}

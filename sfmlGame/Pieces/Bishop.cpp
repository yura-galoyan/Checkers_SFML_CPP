#include "Bishop.hpp"

std::unique_ptr<Piece> Bishop::clone() const
{
    return std::unique_ptr<Piece>();
}

void Bishop::move(Coords xy)
{
}

void Bishop::draw(Window &window)
{
}

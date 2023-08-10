#include "Queen.hpp"

std::unique_ptr<Piece> Queen::clone() const
{
    return std::unique_ptr<Piece>();
}

void Queen::move(Coords xy)
{
}

void Queen::draw(Window& window)
{
}

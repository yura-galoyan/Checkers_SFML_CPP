#include "Rook.hpp"

std::unique_ptr<Piece> Rook::clone() const
{
    return std::unique_ptr<Piece>();
}

void Rook::move(Coords xy)
{
}

void Rook::draw(Window &window)
{
}

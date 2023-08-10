#include "Pawn.hpp"

std::unique_ptr<Piece> Pawn::clone() const
{
    return std::make_unique<Pawn>();
}

void Pawn::move(Coords xy)
{
}

void Pawn::draw() const
{
}

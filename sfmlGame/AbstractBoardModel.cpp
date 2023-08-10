#include "AbstractBoardModel.hpp"

void AbstractBoardModel::addPiece(PiecePtr<> piece)
{
    pieces.push_back(std::move(piece));
}
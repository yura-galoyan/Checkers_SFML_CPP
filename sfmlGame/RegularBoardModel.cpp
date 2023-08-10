#include "RegularBoardModel.hpp"

std::unique_ptr<AbstractBoardModel> RegularBoardModel::clone() const {
    return std::make_unique<RegularBoardModel>();
}

void RegularBoardModel::addPiece(std::unique_ptr<Piece> piece){
    pieces.push_back(std::move(piece));
}

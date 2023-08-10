#include "RegularBoardModel.hpp"

std::unique_ptr<AbstractBoardModel> RegularBoardModel::clone() const {
    return std::make_unique<RegularBoardModel>();
}


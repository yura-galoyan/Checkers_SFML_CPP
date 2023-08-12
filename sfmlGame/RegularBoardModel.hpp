#ifndef REGULAR_BOARD_MODEL_HPP
#define REGULAR_BOARD_MODEL_HPP

#include "AbstractBoardModel.hpp"

#include <vector>

class RegularBoardModel : public AbstractBoardModel
{
public:
   RegularBoardModel() = default;
   RegularBoardModel(const RegularBoardModel&) = default;
   virtual std::unique_ptr<AbstractBoardModel> clone() const override;

};

#endif //REGULAR_BOARD_MODEL_HPP
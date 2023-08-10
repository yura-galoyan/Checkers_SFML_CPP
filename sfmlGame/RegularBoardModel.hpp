#ifndef REGULAR_BOARD_MODEL_HPP
#define REGULAR_BOARD_MODEL_HPP

#include "AbstractBoardModel.hpp"

#include <vector>

class RegularBoardModel : public AbstractBoardModel
{
public:
   virtual std::unique_ptr<AbstractBoardModel> clone() const override;

public:
    virtual void addPiece(std::unique_ptr<Piece>) override;

private:
    std::vector<std::unique_ptr<Piece>> pieces;
};

#endif //REGULAR_BOARD_MODEL_HPP
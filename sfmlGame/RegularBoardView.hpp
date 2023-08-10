#ifndef REGULAR_BOARD_VIEW_HPP
#define REGULAR_BOARD_VIEW_HPP

#include "AbstractBoardView.hpp"
#include "AbstractBoardModel.hpp"

class RegularBoardView : public AbstractBoardView
{
public:
    RegularBoardView() = default;
    RegularBoardView(AbstractBoardModel* model);

public:
    void draw(Window& window) override ;
};


#endif //REGULAR_BOARD_VIEW_HPP
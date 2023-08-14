#ifndef REGULAR_BOARD_VIEW_HPP
#define REGULAR_BOARD_VIEW_HPP

#include "AbstractBoardView.hpp"
#include "AbstractBoardModel.hpp"



class RegularBoardView : public AbstractBoardView
{
public:
    RegularBoardView() = default;
    RegularBoardView(std::unique_ptr<AbstractBoardModel> model);

public:
    void draw(Window& window, Texture& texture) override ;
};


#endif //REGULAR_BOARD_VIEW_HPP
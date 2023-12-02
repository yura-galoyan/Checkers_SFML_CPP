#ifndef UPSIDE_DOWN_BOARD_VIEW_HPP
#define UPSIDE_DOWN_BOARD_VIEW_HPP

#include <SFML/Graphics/RectangleShape.hpp>

#include "RegularBoardModel.hpp"

#include "iBoardView.hpp"

class UpsideDownBoardView : public iBoardView
{
public:
    UpsideDownBoardView() = default;
    UpsideDownBoardView(std::shared_ptr<RegularBoardModel> model);

public:
    void draw(Window& window) override ;

};


#endif //UPSIDE_DOWN_BOARD_VIEW_HPP
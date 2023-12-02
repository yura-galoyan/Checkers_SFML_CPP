#ifndef REGULAR_BOARD_VIEW_HPP
#define REGULAR_BOARD_VIEW_HPP

#include <SFML/Graphics/RectangleShape.hpp>

#include "RegularBoardModel.hpp"

#include "iBoardView.hpp"

class RegularBoardView : public iBoardView
{
public:
    RegularBoardView() = default;
    RegularBoardView(std::shared_ptr<RegularBoardModel> model);

public:
    void draw(Window& window) override;

};


#endif //REGULAR_BOARD_VIEW_HPP
#ifndef REGULAR_BOARD_VIEW_HPP
#define REGULAR_BOARD_VIEW_HPP

#include "AbstractBoardView.hpp"
#include "AbstractBoardModel.hpp"

#include <SFML/Graphics/RectangleShape.hpp>

class RegularBoardView : public AbstractBoardView
{
public:
    RegularBoardView();
    RegularBoardView(std::unique_ptr<AbstractBoardModel> model);

public:
    void draw(Window& window) override ;

private:
    void highlightCurrPiece(Window& window) override;
    void highlightValidMoves(int i, int j, Window& window) override;
    void highlightCheckedPiece(Window& window) override;

private:
    sf::RectangleShape highlighter;
    sf::RectangleShape movesHighlighter;
    sf::RectangleShape checkHighlighter;
};


#endif //REGULAR_BOARD_VIEW_HPP
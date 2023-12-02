#ifndef REGULAR_BOARD_VIEW_HPP
#define REGULAR_BOARD_VIEW_HPP

#include <SFML/Graphics/RectangleShape.hpp>

#include "RegularBoardModel.hpp"

class RegularBoardView
{
public:
    RegularBoardView();
    RegularBoardView(std::unique_ptr<RegularBoardModel> model);

public:
    void draw(Window& window)  ;

private:
    void highlightCurrPiece(Window& window);
    void highlightValidMoves(int i, int j, Window& window);
    void highlightCheckedPiece(Window& window);
    void setModel(std::unique_ptr<RegularBoardModel> model_);

private:
    /// @brief FIXME: ????
    sf::RectangleShape highlighter;
    sf::RectangleShape movesHighlighter;
    sf::RectangleShape checkHighlighter;

private:
    std::unique_ptr<RegularBoardModel> m_model;

};


#endif //REGULAR_BOARD_VIEW_HPP
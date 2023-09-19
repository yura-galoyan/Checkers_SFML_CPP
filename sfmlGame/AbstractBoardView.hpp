#ifndef ABSTRACT_BOARD_VIEW_HPP
#define ABSTRACT_BOARD_VIEW_HPP

#include "System/Window.hpp"
#include "System/Texture.hpp"

#include <memory>

class AbstractBoardModel;
class AbstractBoardView
{
public:
    void setModel(std::unique_ptr<AbstractBoardModel> model);
    virtual void draw(Window& window) = 0;
    virtual void highlightCurrPiece(Window& window) = 0;
    virtual void highlightValidMoves(int i, int j, Window& window) = 0;
    virtual void highlightCheckedPiece(Window& window) = 0;

protected:
    std::unique_ptr<AbstractBoardModel> model;

};

#endif //ABSTRACT_BOARD_VIEW_HPP
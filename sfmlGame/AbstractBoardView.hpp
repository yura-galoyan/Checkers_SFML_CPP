#ifndef ABSTRACT_BOARD_VIEW_HPP
#define ABSTRACT_BOARD_VIEW_HPP

#include "Window.hpp"

#include "Texture.hpp"

class AbstractBoardModel;
class AbstractBoardView
{
public:
    void setModel(AbstractBoardModel* model);
    virtual void draw(Window& window, Texture& texture) = 0;

protected:
    AbstractBoardModel* model;

};

#endif //ABSTRACT_BOARD_VIEW_HPP
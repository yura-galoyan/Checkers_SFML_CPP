#include "UpsideDownBoardView.hpp"

#include <vector>

#include "../Constants/BoardConstants.hpp"

template <typename T>
struct reversion_wrapper { T& iterable; };

template <typename T>
auto begin (reversion_wrapper<T> w) { return std::rbegin(w.iterable); }

template <typename T>
auto end (reversion_wrapper<T> w) { return std::rend(w.iterable); }

template <typename T>
reversion_wrapper<T> reverse (T&& iterable) { return { iterable }; }


UpsideDownBoardView::UpsideDownBoardView(std::shared_ptr<RegularBoardModel> model)
    : iBoardView(model)
{
}

#include <iostream>

void UpsideDownBoardView::draw(Window &window)
{
    for(auto& objects : reverse(*m_model)){
        for(auto& object : reverse(objects)){
            if(object){
                auto pos = object->getSprite().getPosition();
                object->draw(window,{ 7 * CELL_SIZE - ( pos.x - BOARD_POS_X) + BOARD_POS_X, 7 * CELL_SIZE - ( pos.y - BOARD_POS_Y) + BOARD_POS_Y });
            }
        }
    }
}

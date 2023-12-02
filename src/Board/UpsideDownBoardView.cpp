#include "UpsideDownBoardView.hpp"


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

void UpsideDownBoardView::draw(Window &window)
{
    for(auto& objects : reverse(*m_model)){
        for(auto& object : reverse(objects)){
            if(object){
                object->draw(window);
            }
        }
    }
}

#include "RegularBoardView.hpp"


RegularBoardView::RegularBoardView(AbstractBoardModel* model){
    setModel(model);
}

void RegularBoardView::draw(Window& window, Texture& texture){
    
    for(auto &object : *model){
        object->draw(window, texture);
    }
}

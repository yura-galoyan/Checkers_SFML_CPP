#include "RegularBoardView.hpp"


RegularBoardView::RegularBoardView(AbstractBoardModel* model){
    setModel(model);
}

void RegularBoardView::draw(Window& window){
    for(auto &object : *model){
        object->draw();
    }
}

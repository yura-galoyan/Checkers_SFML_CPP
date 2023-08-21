#include "RegularBoardView.hpp"


RegularBoardView::RegularBoardView(std::unique_ptr<AbstractBoardModel> model){
    setModel(std::move(model));
}

void RegularBoardView::draw(Window& window){
    
    for(auto &object : *model){
        object->draw(window);
    }
}

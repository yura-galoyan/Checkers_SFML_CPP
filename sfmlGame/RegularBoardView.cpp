#include "RegularBoardView.hpp"


RegularBoardView::RegularBoardView(std::unique_ptr<AbstractBoardModel> model){
    setModel(std::move(model));
}

void RegularBoardView::draw(Window& window){
    
    for(auto& objects : *model){
        for(auto& object : objects ){
            if(object){
                object->draw(window);
            }     
        }
    }
}

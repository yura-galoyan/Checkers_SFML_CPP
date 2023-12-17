#include "RegularBoardView.hpp"
#include <iostream> 
RegularBoardView::RegularBoardView(std::shared_ptr<RegularBoardModel> model)
:iBoardView{model}
{
}

void RegularBoardView::draw(Window &window)
{
    for(auto& objects : *m_model){
        for(auto& object : objects ){
            if(object){
                object->draw(window);
            }  
        }
    }
}

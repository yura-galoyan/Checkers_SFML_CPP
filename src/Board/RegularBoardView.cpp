#include "RegularBoardView.hpp"

RegularBoardView::RegularBoardView(std::shared_ptr<RegularBoardModel> model)
:iBoardView{model}
{
}

void RegularBoardView::draw(Window &window)
{

    int i = 0,j = 0;

    for(auto& objects : *m_model){
        for(auto& object : objects ){
            if(object){
                object->draw(window);
            }
        }
    }
}

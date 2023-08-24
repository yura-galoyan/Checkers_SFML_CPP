#include "RegularBoardView.hpp"

RegularBoardView::RegularBoardView(){
    highlighter.setOutlineColor(sf::Color::Red);
    highlighter.setOutlineThickness(2);
    highlighter.setFillColor(sf::Color::Transparent);
    highlighter.setSize({110,110});
}

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
    highlightCurrPiece(window);
}

void RegularBoardView::highlightCurrPiece(Window& window){
    if(model->getCurrPiece() && model->isValidCoordinate( model->getCurrPiece()->getXY().first, model->getCurrPiece()->getXY().second )){
        highlighter.setPosition( model->getCurrPiece()->getXY().first * 110, model->getCurrPiece()->getXY().second * 110  );
        window.draw(highlighter);
    }
}

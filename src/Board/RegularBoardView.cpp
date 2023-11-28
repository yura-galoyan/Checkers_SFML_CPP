#include "RegularBoardView.hpp"

RegularBoardView::RegularBoardView(){
    highlighter.setOutlineColor(sf::Color::Red);
    highlighter.setOutlineThickness(2);
    highlighter.setFillColor(sf::Color::Transparent);
    highlighter.setSize({110,110});
    
    movesHighlighter.setFillColor(sf::Color(255,255,0,64)); 
    movesHighlighter.setSize({110,110});

    checkHighlighter = highlighter;
    checkHighlighter.setOutlineColor(sf::Color::Green);
}

RegularBoardView::RegularBoardView(std::unique_ptr<AbstractBoardModel> model){
    setModel(std::move(model));
}

void RegularBoardView::draw(Window& window){
    for(auto& move : model->getValidMoves()){
        highlightValidMoves(move.first, move.second,window);
    }
    
    for(auto& objects : *model){
        for(auto& object : objects ){
            if(object){
                object->draw(window);
            }
        }
    }

    highlightCurrPiece(window);
    highlightCheckedPiece(window);
}

void RegularBoardView::highlightCurrPiece(Window& window){
    if(model->getCurrPiece() && model->isValidCoordinate( model->getCurrPiece()->getXY().first, model->getCurrPiece()->getXY().second )){
        highlighter.setPosition( model->getCurrPiece()->getXY().first * 110, model->getCurrPiece()->getXY().second * 110  );
        window.draw(highlighter);
    }
}

void RegularBoardView::highlightValidMoves(int i, int j, Window &window){

    movesHighlighter.setPosition(j * 110, i * 110  );
    window.draw(movesHighlighter);
}


void RegularBoardView::highlightCheckedPiece(Window &window){
    if(model->getCheckedPiece()){
        checkHighlighter.setPosition( model->getCheckedPiece()->getXY().first * 110, model->getCheckedPiece()->getXY().second * 110);
        window.draw(checkHighlighter);
    }
}

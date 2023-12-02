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

RegularBoardView::RegularBoardView(std::unique_ptr<RegularBoardModel> model){
    setModel(std::move(model));
}


void RegularBoardView::setModel(std::unique_ptr<RegularBoardModel> model_){
    this->m_model = std::move(model_);
}

void RegularBoardView::draw(Window& window){
    for(auto& move : m_model->getValidMoves()){
        highlightValidMoves(move.first, move.second,window);
    }
    
    for(auto& objects : *m_model){
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
    auto currPiece = m_model->getCurrPiece();
    if(currPiece && m_model->isValidCoordinate( currPiece->getXY().first, currPiece->getXY().second )){
        highlighter.setPosition( currPiece->getXY().first * 110, currPiece->getXY().second * 110  );
        window.draw(highlighter);
    }
}

void RegularBoardView::highlightValidMoves(int i, int j, Window &window){

    movesHighlighter.setPosition(j * 110, i * 110  );
    window.draw(movesHighlighter);
}


void RegularBoardView::highlightCheckedPiece(Window &window){
    if(m_model->getCheckedPiece()){
        checkHighlighter.setPosition( m_model->getCheckedPiece()->getXY().first * 110, m_model->getCheckedPiece()->getXY().second * 110);
        window.draw(checkHighlighter);
    }
}

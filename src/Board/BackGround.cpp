#include "BackGround.hpp"
// #include "CellSizeController.hpp"
#include "../Constants/BoardConstants.hpp"
#include <iostream>
void BackGround::draw(Window& window){

    for(short int i = 0; i < 8; ++i){
        for(short int j = 0; j < 8; ++j){
            if((i + j) % 2){
                m_whiteCell.setPosition(m_pos.x + i * 110, m_pos.y +  j * 110);
                m_whiteCell.draw(window);
            }
            else{
                m_blackCell.setPosition(m_pos.x + i * 110, m_pos.y +  j * 110);
                m_blackCell.draw(window);
            }
        }
    }
}

void BackGround::setTexture(Texture* texture){
    m_texture = texture;
}

void BackGround::initSprites(){
    
    // 1. Black
    // 2. White

    m_whiteCell.setTexture(m_texture);
    m_whiteCell.setStartingRect({1,1}, {110,110});


    m_blackCell.setTexture(m_texture);
    m_blackCell.setStartingRect({1,112}, {110,110});
 
}

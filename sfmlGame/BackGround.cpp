#include "BackGround.hpp"
#include "CellSizeController.hpp"

void BackGround::draw(Window& window){
    for(auto sprite : sprites){
        sprite.draw(window);
    }

}

void BackGround::initSprites(float offsetX, Texture& texture){
    
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            Sprite sprite;
            if( (i  + j) % 2){
                sprite.setStartingRect({1 + 6 * 60, 1}, {110,110});
            }
            else{
                sprite.setStartingRect({1 + 6 * 60, 112}, {110,110});
            }
            sprite.setTexture(&texture);
            sprite.setPosition(i * 110 + offsetX,j * 110);
            sprites.push_back(sprite);
        }
    }    
}

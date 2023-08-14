#include "Sprite.hpp"

Sprite::Sprite(Vector2i position, Vector2i size){
    setRect(position, size);
}

void Sprite::setTexture(Texture* texture_){
    this->texture = texture_;
    if(texture_){
        sprite.setTexture(texture_->getTexture());
    }
}

void Sprite::draw(Window &window){
    window.draw(sprite);
}

void Sprite::setRect(Vector2i position, Vector2i size){
    this->position = position;
    this->size = size;

    sprite.setTextureRect({position,size});
}

void Sprite::setRectPosY(int y){
    position.y = y;
    sprite.setTextureRect({position,size});
}

void Sprite::setPosition(float x, float y){
    sprite.setPosition(x,y);
}

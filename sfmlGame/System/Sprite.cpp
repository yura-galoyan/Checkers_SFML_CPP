#include "Sprite.hpp"

Sprite::Sprite(Vector2i rectPosition, Vector2i size){
    setStartingRect(rectPosition, size);
    setDistanceX(size.x + 2);
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

void Sprite::setScale(std::pair<float, float> scale){
    sprite.setScale(scale.first, scale.second);
}

void Sprite::setStartingRect(Vector2i position, Vector2i size_){
    startingRectPos = {position.x, position.y};
    size = {size_.x, size_.y};
    setDistanceX(size_.x + 2);

    currRectPosition = startingRectPos;

    sprite.setTextureRect({startingRectPos, size});
}


void Sprite::setCurrRectPosY(int y){
    currRectPosition.y = y;
    sprite.setTextureRect({currRectPosition, size});
}

void Sprite::setCurrRectPosX(int x){
    currRectPosition.x = x;
    sprite.setTextureRect({currRectPosition, size});
}

void Sprite::setPosition(float x, float y){
    sprite.setPosition(x,y);
}

void Sprite::setDistanceX(unsigned x){
    distanceX = x;
}

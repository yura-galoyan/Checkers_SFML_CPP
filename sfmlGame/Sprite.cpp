#include "Sprite.hpp"

Sprite::Sprite(Texture* texture_, sf::Vector2i position_, sf::Vector2i size_)
    :texture{texture_}, position{position_}, size{size_}
{
    sprite.setTexture(texture->getTexture());
    setRect(position, size);
}

void Sprite::setTexture(Texture* texture_){
    this->texture = texture;
}

void Sprite::draw(Window &window){
    window.draw(sprite);
}

void Sprite::setRect(sf::Vector2i pos, sf::Vector2i size){
    sprite.setTextureRect(sf::IntRect{pos, size});
}

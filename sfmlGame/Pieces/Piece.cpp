#include "Piece.hpp"

void Piece::setPosition(std::size_t x){
    static bool b{true};

    if(b){
        setXY({x,0});
        setColor(Piece::Color::Black);
        b = !b;
    }
    else if(!b){
        setXY({x,7});
        setColor(Piece::Color::White);
        b = !b;
        sprite.setPosition( sprite.getPosition().x , sprite.getPosition().y + 131);
    }
}

void Piece::setSprite(const Sprite &sprite_){
    sprite = sprite_;
}

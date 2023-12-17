#include "Piece.hpp"

#include "../Constants/BoardConstants.hpp"

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
        sprite.setPosition( sprite.getPosition().x , sprite.getPosition().y + 7 * 110);
    }
}

void Piece::moveTo(Coords xy){
    setXY(xy);
    sprite.setPosition(xy.first * 110  + BOARD_POS_X, xy.second * 110 + BOARD_POS_Y);
}


void Piece::setSprite(const Sprite &sprite_){
    sprite = sprite_;
}

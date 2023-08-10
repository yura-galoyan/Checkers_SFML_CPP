#include "Piece.hpp"

void Piece::setPosition(std::size_t x)
{
    static bool b{true};

    if(b){
        setXY({x,0});
        setColor(Piece::Color::Black);
        b = !b;
    }
    if(b){
        setXY({x,7});
        setColor(Piece::Color::White);
    }
}

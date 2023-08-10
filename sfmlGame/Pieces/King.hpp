#ifndef KING_HPP
#define KING_HPP

#include "Piece.hpp"

class King : public Piece
{
    virtual std::unique_ptr<Piece> clone() const override ;
    virtual void move(Coords xy) override ;
    virtual void draw(Window& window) override  ;

};


#endif //KING_HPP
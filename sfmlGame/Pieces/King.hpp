#ifndef KING_HPP
#define KING_HPP

#include "Piece.hpp"

class King : public Piece
{
    virtual std::unique_ptr<Piece> clone() const ;
    virtual void move(Coords xy) ;
    virtual void draw() const ;

};


#endif //KING_HPP
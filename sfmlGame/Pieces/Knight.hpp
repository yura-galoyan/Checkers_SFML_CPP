#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "Piece.hpp"

class Knight : public Piece
{

    virtual std::unique_ptr<Piece> clone() const ;
    virtual void move(Coords xy) ;
    virtual void draw() const ;
};

#endif //KNIGHT_HPP


#ifndef ROOK_HPP
#define ROOK_HPP

#include "Piece.hpp"

class Rook : public Piece
{

    virtual std::unique_ptr<Piece> clone() const ;
    virtual void move(Coords xy) ;
    virtual void draw() const ;
};


#endif //ROOK_HPP
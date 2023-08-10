#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "Piece.hpp"

class Bishop : public Piece
{
    
    virtual std::unique_ptr<Piece> clone() const ;
    virtual void move(Coords xy) ;
    virtual void draw() const ;
}; 

#endif //BISHOP_HPP
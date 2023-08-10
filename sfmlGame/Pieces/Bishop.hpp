#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "Piece.hpp"

class Bishop : public Piece
{
    
    virtual std::unique_ptr<Piece> clone() const override ;
    virtual void move(Coords xy) override ;
    virtual void draw(Window& window) override ;
}; 

#endif //BISHOP_HPP
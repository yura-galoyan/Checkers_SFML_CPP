#ifndef QUENN_HPP
#define QUENN_HPP

#include "Piece.hpp"

class Queen : public Piece
{

    virtual std::unique_ptr<Piece> clone() const ;
    virtual void move(Coords xy) ;
    virtual void draw() const ;
};

#endif //QUENN_HPP
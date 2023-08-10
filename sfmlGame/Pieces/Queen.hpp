#ifndef QUENN_HPP
#define QUENN_HPP

#include "Piece.hpp"

class Queen : public Piece
{

    virtual std::unique_ptr<Piece> clone() const override ;
    virtual void move(Coords xy) override ;
    virtual void draw(Window& window) override ;
};

#endif //QUENN_HPP
#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "Piece.hpp"

class Knight : public Piece
{
public:
    Knight() = default;
    Knight(const Knight& k){}
    virtual std::unique_ptr<Piece> clone() const override ;
    virtual void move(Coords xy) override ;
    virtual void draw(Window& window) override ;
};

#endif //KNIGHT_HPP


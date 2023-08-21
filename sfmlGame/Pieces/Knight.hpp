#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "Piece.hpp"

class Knight : public Piece
{
public:
    Knight() = default;
    Knight(const Knight& k){}
    std::unique_ptr<Piece> clone() const override ;
    void moveTo(Coords xy) override ;
    void draw(Window& window) override ;
};

#endif //KNIGHT_HPP


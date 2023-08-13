#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "Piece.hpp"

class Knight : public Piece
{
public:
    Knight() = default;
    Knight(const Knight& k){}
    std::unique_ptr<Piece> clone() const override ;
    void move(Coords xy) override ;
    void draw(Window& window, Texture& texture) override ;
};

#endif //KNIGHT_HPP


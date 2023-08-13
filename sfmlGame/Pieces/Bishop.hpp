#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "Piece.hpp"

class Bishop : public Piece
{
public:
    Bishop() = default;
    Bishop(const Bishop& k){}
    std::unique_ptr<Piece> clone() const override ;
    void move(Coords xy) override ;
    void draw(Window& window, Texture& texture) override ;
}; 

#endif //BISHOP_HPP
#ifndef QUENN_HPP
#define QUENN_HPP

#include "Piece.hpp"

class Queen : public Piece
{

public:
    Queen() = default;
    Queen(const Queen& q){}

public:
    std::unique_ptr<Piece> clone() const override ;
    void moveTo(Coords xy) override ;
    void draw(Window& window, Texture& texture) override ;


};

#endif //QUENN_HPP
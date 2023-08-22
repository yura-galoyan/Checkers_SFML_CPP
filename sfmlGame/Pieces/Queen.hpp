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
    bool isValid(Coords from, Coords to) const override;
    void draw(Window& window) override ;


};

#endif //QUENN_HPP
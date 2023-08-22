#ifndef ROOK_HPP
#define ROOK_HPP

#include "Piece.hpp"

class Rook : public Piece
{
public:
    Rook() = default;
    Rook(const Rook& q){}
    std::unique_ptr<Piece> clone() const override ;
    bool isValid(Coords from, Coords to) const override;
    void draw(Window& window) override ;
    
};


#endif //ROOK_HPP
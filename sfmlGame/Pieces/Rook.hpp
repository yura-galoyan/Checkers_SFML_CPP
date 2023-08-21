#ifndef ROOK_HPP
#define ROOK_HPP

#include "Piece.hpp"

class Rook : public Piece
{
public:
    Rook() = default;
    Rook(const Rook& q){}
    std::unique_ptr<Piece> clone() const override ;
    void moveTo(Coords xy) override ;
    void draw(Window& window) override ;
    
};


#endif //ROOK_HPP
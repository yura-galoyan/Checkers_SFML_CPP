#ifndef KING_HPP
#define KING_HPP

#include "Piece.hpp"

class King : public Piece
{
public:
    King() = default;
    King(const King& k){}
    std::unique_ptr<Piece> clone() const override ;
    bool isValid(Coords from, Coords to) const override;
    void draw(Window& window) override  ;

};


#endif //KING_HPP
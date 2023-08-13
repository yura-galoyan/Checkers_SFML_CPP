#ifndef KING_HPP
#define KING_HPP

#include "Piece.hpp"

class King : public Piece
{
public:
    King() = default;
    King(const King& k){}
    std::unique_ptr<Piece> clone() const override ;
    void move(Coords xy) override ;
    void draw(Window& window, Texture& texture) override  ;

};


#endif //KING_HPP
#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "Piece.hpp"

class Bishop : public Piece
{
public:
    Bishop() = default;
    Bishop(const Bishop& k){}
    std::unique_ptr<Piece> clone() const override ;
    bool isValid(Coords from, Coords to) const override;
    void draw(Window& window) override ;

private:

}; 

#endif //BISHOP_HPP
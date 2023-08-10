#ifndef PAWN_HPP
#define PAWN_HPP

#include "Piece.hpp"

class Pawn : public Piece 
{
public:
    virtual std::unique_ptr<Piece> clone() const override;
    virtual void move(Coords xy) ;
    virtual void draw() const ;
private:
};

#endif //PAWN_HPP
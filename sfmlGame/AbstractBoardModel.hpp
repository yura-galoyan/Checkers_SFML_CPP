#ifndef ABSTRACT_BOARD_MODEL_HPP
#define ABSTRACT_BOARD_MODEL_HPP

#include "Pieces/Piece.hpp"



class AbstractBoardModel
{
public:
   template<typename T = Piece>
   using PiecePtr = std::unique_ptr<T>;
   
public:
   virtual std::unique_ptr<AbstractBoardModel> clone() const = 0;
   virtual ~AbstractBoardModel() = default;

public:
   virtual void addPiece(PiecePtr<> piece) = 0; 
};


#endif //ABSTRACT_BOARD_MODEL_HPP
#ifndef ABSTRACT_BOARD_MODEL_HPP
#define ABSTRACT_BOARD_MODEL_HPP

#include "Pieces/Piece.hpp"


#include <vector>


class AbstractBoardModel
{
public:
   template<typename T = Piece>
   using PiecePtr = std::unique_ptr<T>;
   
public:
   virtual std::unique_ptr<AbstractBoardModel> clone() const = 0;
   virtual ~AbstractBoardModel() = default;

public:
   void addPiece(PiecePtr<> piece) ;

public:
   auto begin() { return pieces.begin();  }
   auto begin() const  { return pieces.begin();  }
   auto cbegin() const { return pieces.cbegin(); }
   auto end() { return pieces.end();  }
   auto end() const { return pieces.end();  }
   auto cend() const { return pieces.cend(); }


private:
    std::vector<std::unique_ptr<Piece>> pieces;

};


#endif //ABSTRACT_BOARD_MODEL_HPP
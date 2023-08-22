#ifndef ABSTRACT_BOARD_MODEL_HPP
#define ABSTRACT_BOARD_MODEL_HPP

#include "Pieces/Piece.hpp"

#include <memory>
#include <vector>


class AbstractBoardModel
{
public:
   template<typename T = Piece>
   using PiecePtr = std::unique_ptr<T>;
   
public:
   AbstractBoardModel();
   virtual ~AbstractBoardModel() = default;

public:
   void addPiece(PiecePtr<> piece) ;
   void movePiece(int oldX, int oldY, int newX, int newY);
   bool isValidMove(std::pair<int,int> from, std::pair<int, int> to);
   bool isValidCoordinate(int x, int y);

public:
   auto begin() { return piecePtrVec.begin();  }
   auto begin() const  { return piecePtrVec.begin();  }
   auto cbegin() const { return piecePtrVec.cbegin(); }
   auto end() { return piecePtrVec.end();  }
   auto end() const { return piecePtrVec.end();  }
   auto cend() const { return piecePtrVec.cend(); }



private:
    std::vector<std::unique_ptr<Piece>> pieces;
    std::vector<std::vector<PiecePtr<>>> piecePtrVec;

};


#endif //ABSTRACT_BOARD_MODEL_HPP
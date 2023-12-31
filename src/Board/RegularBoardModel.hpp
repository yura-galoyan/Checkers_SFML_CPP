#ifndef ABSTRACT_BOARD_MODEL_HPP
#define ABSTRACT_BOARD_MODEL_HPP

#include "../Pieces/Piece.hpp"

#include <memory>
#include <vector>


class RegularBoardModel
{
public:
   template<typename T = Piece>
   using PiecePtr = std::unique_ptr<T>;
   
public:
   RegularBoardModel();
   ~RegularBoardModel() = default;

public:
   void addPiece(PiecePtr<> piece) ;
   void movePiece(int oldX, int oldY, int newX, int newY);
   
public:
   bool isValidMove(std::pair<int,int> from, std::pair<int, int> to);
   bool isValidCoordinate(int x, int y);
   bool isColor(Piece::Color color, int x, int y   );
   bool isSameColor(std::pair<int,int> from, std::pair<int, int> to);


   bool isTurnOf(Piece::Color color);
   void changeTurn();

   Piece::Color getColor(int x, int y) { if(piecePtrVec[x][y]) return piecePtrVec[x][y]->getColor(); };   
   Piece::Color getTurn() { return turn; }
   
   
   void setCurrPiece(int x, int y);
   void setCurrPiece(Piece*);

   void setCheckedPiece(int x, int y);
   void resetChecking();

   Piece* getCurrPiece() { return currPiece; }
   Piece* getCheckedPiece() { return checkedPiece; }
   std::vector<std::pair<int,int>>& getValidMoves() { return validMoves; }
   void clearValidMoves() { validMoves.clear(); }
   void setValidMoves(std::vector<std::pair<int,int>>&& moves);
   void setValidMoves(std::vector<std::pair<int,int>>& moves);

public:
   auto begin() { return piecePtrVec.begin();  }
   auto begin() const  { return piecePtrVec.begin();  }
   auto cbegin() const { return piecePtrVec.cbegin(); }
   auto end() { return piecePtrVec.end();  }
   auto end() const { return piecePtrVec.end();  }
   auto cend() const { return piecePtrVec.cend(); }

public:
   auto rbegin() { return piecePtrVec.rbegin();  }
   auto rbegin() const  { return piecePtrVec.rbegin();  }
   auto crbegin() const { return piecePtrVec.crbegin(); }
   auto rend() { return piecePtrVec.rend();  }
   auto rend() const { return piecePtrVec.rend();  }
   auto crend() const { return piecePtrVec.crend(); }

   

private:
   std::vector<std::vector<PiecePtr<>>> piecePtrVec;
   std::vector<std::pair<int,int>> validMoves;
   Piece* currPiece;
   Piece* checkedPiece;
   Piece::Color turn{Piece::Color::White};
};


#endif //ABSTRACT_BOARD_MODEL_HPP
#ifndef CHESS_JUDGE_HPP
#define CHESS_JUDGE_HPP

#include <vector>

#include "Pieces/Piece.hpp"

class ChessJudge
{
public:
    using ValidMovesVector = std::vector<std::pair<int,int>>;
public:
    ChessJudge();
    bool isValid(std::pair<int, int> from, std::pair<int, int> to);
    ValidMovesVector getValidMoves(int, int );
    void movePiece(std::pair<int, int> from, std::pair<int, int> to);
    
private:
    enum c_Piece { empty, w_Pawn , w_Rook, w_Knight,w_Bishop, w_Queen, w_King,  difference = 50,
                   border = 150,  b_Pawn, b_Rook,  b_Knight, b_Bishop,b_Queen, b_King
    };

private:
    ValidMovesVector computeRookMoves(int, int);
    void computeRookMovesHorizontal(int i, int j, int directionSign,ValidMovesVector& validMoves);
    void computeRookMovesVertical(int i, int j, int directionSign,ValidMovesVector& validMoves);

private:
    ValidMovesVector computeKnightMoves(int, int);
    bool isValidKnightMove( int sefl_i, int sefl_j, int i, int j);

private:
    ValidMovesVector computeBishopMoves(int, int);
    void computeBishopMovesHelper(int,int, int directionSign1, int directionSigh2, ValidMovesVector& validMoves);

private:
    ValidMovesVector computePawnMoves(int, int);
    void computePawnMovesHelper(int, int, int verticalDirectionValue, ValidMovesVector& validMoves);

private:
    ValidMovesVector computeQueenMoves(int,int);

protected:
    std::vector<std::vector<c_Piece> > board;
    Piece::Color turn{Piece::Color::White};
};

#endif //CHESS_JUDGE_HPP
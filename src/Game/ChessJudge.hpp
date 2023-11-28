#ifndef CHESS_JUDGE_HPP
#define CHESS_JUDGE_HPP

#include <vector>

#include "Pieces/Piece.hpp"

class ChessJudge
{
private:
    enum c_Piece { empty = 75, w_Pawn = 1 , w_Rook, w_Knight,w_Bishop, w_Queen, w_King,  difference = 100,
                   border = 150,  b_Pawn, b_Rook,  b_Knight, b_Bishop,b_Queen, b_King
    };


public:
    using ValidMovesVector = std::vector<std::pair<int,int>>;
public:
    ChessJudge();
    bool isValid(std::pair<int, int> from, std::pair<int, int> to);
    ValidMovesVector getPossibleMoves(int, int );
    ValidMovesVector getValidMoves(int, int);
    void movePiece(std::pair<int, int> from, std::pair<int, int> to);
    void addMove(std::pair<int,int> ij, std::pair<int,int>, ValidMovesVector& validMoves);
    bool isCheck(int i, int j); 
    void checkForChecks();
    void changeTurn();
    void checkForCheckedking(bool& checked);
    bool isTurnOf(c_Piece p);

    void setIsChecked(bool state) { isChecked = state; };
    bool getIsChecked() { return isChecked; };

    std::pair<int,int> getCheckedKing();

private:
    ValidMovesVector computeRookMoves(int, int);
    void computeRookMovesHorizontal(int i, int j, int directionSign,ValidMovesVector& validMoves);
    void computeRookMovesVertical(int i, int j, int directionSign,ValidMovesVector& validMoves);

private:
    ValidMovesVector computeKnightMoves(int, int);
    bool isValidKnightMove( int self_i, int self_j, int i, int j);

private:
    ValidMovesVector computeBishopMoves(int, int);
    void computeBishopMovesHelper(int,int, int directionSign1, int directionSigh2, ValidMovesVector& validMoves);

private:
    ValidMovesVector computePawnMoves(int, int);
    void computePawnMovesHelper(int, int, int verticalDirectionValue, ValidMovesVector& validMoves);

private:
    ValidMovesVector computeQueenMoves(int,int);

private:
    ValidMovesVector computeKingMoves(int, int);

protected:
    std::vector<std::vector<c_Piece> > board;
    Piece::Color turn{Piece::Color::White};
    bool isChecked{false};
    std::pair<int,int> checkedKing;
};

#endif //CHESS_JUDGE_HPP
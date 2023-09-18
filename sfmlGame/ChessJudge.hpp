#ifndef CHESS_JUDGE_HPP
#define CHESS_JUDGE_HPP

#include <vector>

#include "Pieces/Piece.hpp"

class ChessJudge
{
public:
    struct Diagonals;
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

    struct Diagonals{
        int topLeft : 4;
        int topRight : 4;
        int bottomLeft : 4;
        int bottomRight : 4;
    };

private:
    ValidMovesVector computeRookMoves(int, int);
    void computeRookMovesVertical(int i, int j, int directionSign,ValidMovesVector& validMoves);


    ValidMovesVector computePawnMoves(int, int, int verticalDirectionValue);

protected:
    std::vector<std::vector<c_Piece> > board;
    Piece::Color turn{Piece::Color::White};
};

#endif //CHESS_JUDGE_HPP
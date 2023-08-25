#ifndef CHESS_JUDGE_HPP
#define CHESS_JUDGE_HPP

#include <vector>

#include "Pieces/Piece.hpp"

class ChessJudge
{
public:
    ChessJudge();
    bool isValid(std::pair<int, int> from, std::pair<int, int> to);

private:
    enum c_Piece {w_Pawn , w_Rook, w_Knight,w_Bishop, w_Queen, w_King,  White,
                   Black,  b_Pawn, b_Rook,  b_Knight, b_Bishop,b_Queen, b_King
    };

protected:
    std::vector<std::vector<c_Piece> > board;
    Piece::Color turn{Piece::Color::White};
};

#endif //CHESS_JUDGE_HPP
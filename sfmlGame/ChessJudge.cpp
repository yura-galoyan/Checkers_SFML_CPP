#include "ChessJudge.hpp"
#include <iostream>
#include <iomanip>

ChessJudge::ChessJudge(){
    std::vector<c_Piece> vec0;
    std::vector<c_Piece> vec1;
    std::vector<c_Piece> vec6;
    std::vector<c_Piece> vec7;


    std::vector<c_Piece> vec8(8,empty);

    for(int i = 0; i < 8; ++i){
        vec1.push_back(b_Pawn);
    }

    vec0.push_back(b_Rook);
    vec0.push_back(b_Knight);
    vec0.push_back(b_Bishop);
    vec0.push_back(b_Queen);
    vec0.push_back(b_King);
    vec0.push_back(b_Bishop);
    vec0.push_back(b_Knight);
    vec0.push_back(b_Rook);

    board.push_back(vec0);
    board.push_back(vec1);
    for(int i = 0; i < 4; ++i){
        board.push_back(vec8);
    }

    for(int i = 0; i < 8; ++i){
        vec6.push_back(w_Pawn);
    }

    vec7.push_back(w_Rook);
    vec7.push_back(w_Knight);
    vec7.push_back(w_Bishop);
    vec7.push_back(w_Queen);
    vec7.push_back(w_King);
    vec7.push_back(w_Bishop);
    vec7.push_back(w_Knight);
    vec7.push_back(w_Rook);

    board.push_back(vec6);
    board.push_back(vec7);





}

template<typename Container2d>
[[deprecated]] void printBoard(const Container2d& board){
    for(auto& line : board){
        for(auto& p : line){
            std::cout << std::setw(2) << p << " " ;
        }
        std::cout<<std::endl;
    }
}

bool ChessJudge::isValid(std::pair<int, int> from, std::pair<int, int> to){
    volatile bool valid{false};

    return true;
    
}

ChessJudge::ValidMovesVector ChessJudge::getValidMoves(int i,int j) {
    ValidMovesVector validMoves;
    switch (board[i][j])
    {
    case w_Pawn:
        return computePawnMoves(i,j,-1);
        break;
    case b_Pawn:
        return computePawnMoves(i,j,+1);
        break;
    case w_Rook:
        return computeRookMoves(i,j);
        break;
    case b_Rook:
        return computeRookMoves(i,j);
        break;
    default:
        break;
    }

    return validMoves;
}
ChessJudge::ValidMovesVector ChessJudge::computeRookMoves(int i, int j){
    ValidMovesVector validMoves;
    computeRookMovesVertical(i,j,+1,validMoves);
    computeRookMovesVertical(i,j,-1,validMoves);
    for(int k = j + 1; k < 8; ++k){
        if( board[i][k] == empty){
            validMoves.push_back({i,k});
        }
        else {
                if(std::abs(board[i][j] - board[i][k]) >= difference){
                validMoves.push_back({i,k});
            }
            break;
        }
    
    }     
    for(int k = j - 1; k > -1; --k){
        if( board[i][k] == empty){
            validMoves.push_back({i,k});
        }
        else {
                if(std::abs(board[i][j] - board[i][k]) >= difference){
                validMoves.push_back({i,k});
            }
            break;
        }
    
    }
    return validMoves;
}

void ChessJudge::computeRookMovesVertical(int i, int j, int directionSign, ChessJudge::ValidMovesVector& validMoves){
    for(int k = i + directionSign; k != static_cast<int>(3.5 + directionSign*4.5); k = k + directionSign){
        if( board[k][j] == empty){
            validMoves.push_back({k,j});
        }
        else {
                if(std::abs(board[i][j] - board[k][j]) >= difference){
                    validMoves.push_back({k,j});
            }
            break;
        }
    }      
}


ChessJudge::ValidMovesVector ChessJudge::computePawnMoves(int i, int j, int dir){
    ValidMovesVector validMoves;
    auto right = j + 1;
    auto left =  j - 1;
    auto next = i + dir;
    if(next < 8){
        if( board[next][j] == empty){
            validMoves.push_back({next,j});
            if( std::fabs(i - 3.5 + 2.5*dir) < std::numeric_limits<double>::epsilon()){
                if(board[i + dir*2][j] == empty){
                    validMoves.push_back({i + dir * 2,j});
                }
            }
        }
        if(right < 8  && std::abs(board[next][right] - board[i][j]) == difference){
            validMoves.push_back({next,right});
        }
        if(left > -1 && std::abs(board[next][left] - board[i][j]) == difference){
            validMoves.push_back({next,left});
        }
    }
    return validMoves;
}

void ChessJudge::movePiece(std::pair<int, int> from, std::pair<int, int> to){

    board[to.first][to.second] = board[from.first][from.second];
    board[from.first][from.second] = empty;
    printBoard(board);
}


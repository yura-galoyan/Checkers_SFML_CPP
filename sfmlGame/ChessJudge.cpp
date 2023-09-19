#include <iostream>
#include <utility>
#include <iomanip>
#include <limits>

#include "ChessJudge.hpp"


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

    board.push_back(std::move(vec0));
    board.push_back(std::move(vec1));

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

    board.push_back(std::move(vec6));
    board.push_back(std::move(vec7));

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
    return true;
}

bool ChessJudge::isCheck(){
    isChecked = false;
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            getValidMoves(i,j);
        }
    }

    return isChecked;
}

ChessJudge::ValidMovesVector ChessJudge::getValidMoves(int i,int j) {
    ValidMovesVector validMoves;
    switch (board[i][j])
    {
    case w_Pawn:
    case b_Pawn:
        return computePawnMoves(i,j);
        break;
    case w_Rook:
    case b_Rook:
        return computeRookMoves(i,j);
        break;
    case w_Knight:
    case b_Knight:
        return computeKnightMoves(i,j);
        break;
    case w_Bishop:
    case b_Bishop:
        return computeBishopMoves(i,j);
        break;
    case w_Queen:
    case b_Queen:
        return computeQueenMoves(i,j);
        break;
    case w_King:
    case b_King:
        return computeKingMoves(i,j);
        break;
    default:
        break;
    }
    return validMoves;
}

void ChessJudge::isCheck(int k, int p){
    if((turn == Piece::Color::White && board[k][p] == b_King)|| (turn == Piece::Color::Black && board[k][p] == w_King)){
        checkedKing = {k,p};
        isChecked = true;
    } 
}

ChessJudge::ValidMovesVector ChessJudge::computeQueenMoves(int i, int j){
    ValidMovesVector validMoves1 = computeRookMoves(i,j);
    ValidMovesVector validMoves2 = computeBishopMoves(i,j);
    validMoves1.insert(validMoves1.end(), validMoves2.begin(), validMoves2.end());
    return validMoves1;
}

ChessJudge::ValidMovesVector ChessJudge::computeKingMoves(int i, int j){
    ValidMovesVector validMoves;
    for(int k = i - 1; k < 2 + i ; ++k){
        for(int p = j - 1; p < 2 + j; ++p){
            if( -1 < k && k < 8 && -1 < p && p < 8){
                if(board[k][p] == empty || std::abs(board[k][p] - board[i][j]) >= difference){
                    checkMove(i,j,k,p);
                    addMove({k,p}, validMoves);
                }
            }
        }
    }
    return validMoves;
}
bool ChessJudge::checkMove(int i, int j, int p, int k){
    
}

ChessJudge::ValidMovesVector ChessJudge::computeBishopMoves(int i, int j){
    ValidMovesVector validMoves;
    computeBishopMovesHelper(i,j,-1,-1,validMoves); 
    computeBishopMovesHelper(i,j,-1,1,validMoves); 
    computeBishopMovesHelper(i,j,1,-1,validMoves); 
    computeBishopMovesHelper(i,j,1,1,validMoves);     
    return validMoves;
}

void ChessJudge::computeBishopMovesHelper(int i, int j, int directionSign1, int directionSigh2, ValidMovesVector& validMoves){
    for(int k = i + directionSign1, p = j + directionSigh2;-1 < k && k < 8 && -1 < p && p < 8; k = k + directionSign1, p = p + directionSigh2 ){
        if(board[k][p] == empty){
            isCheck(k,p);
            addMove({k,p}, validMoves);
        } 
        else{
            if(std::abs(board[i][j] - board[k][p]) >= difference){
                isCheck(k,p);
                addMove({k,p}, validMoves);
            }
            break; 
        }
    }
    
}

ChessJudge::ValidMovesVector ChessJudge::computeKnightMoves(int i, int j){
    ValidMovesVector validMoves;
    for(int k = -2; k < 3; ++k){
        for(int p = -2; p < 3; ++p){
            if(p != k && p != -k && p != 0 && k != 0){
                if(isValidKnightMove(i,j,i + k, j + p)){
                    isCheck(i + k,j + p);
                    addMove({i + k, j + p},validMoves);
                }
            }
        }
    }
    return validMoves;
}
bool ChessJudge::isValidKnightMove(int self_i, int self_j, int i, int j){
    if( -1 < i && i < 8 && -1 < j && j < 8){
        if(board[i][j] == empty || std::abs(board[self_i][self_j] - board[i][j]) >= difference ){
            return true;
        }
    };
    return false; 
}


ChessJudge::ValidMovesVector ChessJudge::computeRookMoves(int i, int j){
    ValidMovesVector validMoves;
    computeRookMovesVertical(i,j,+1,validMoves);
    computeRookMovesVertical(i,j,-1,validMoves);
    computeRookMovesHorizontal(i,j,+1,validMoves); 
    computeRookMovesHorizontal(i,j,-1,validMoves); 
    return validMoves;
}

void ChessJudge::computeRookMovesHorizontal(int i, int j, int directionSign,ValidMovesVector& validMoves){
    for(int k = j + directionSign; k != static_cast<int>( 3.5 + directionSign * 4.5 ); k = k + directionSign){
        if( board[i][k] == empty){
            addMove({i,k},validMoves);
        }
        else{
            if(std::abs(board[i][j] - board[i][k]) >= difference){
                isCheck(i,k);
                addMove({i,k},validMoves);
            }
            break;
        }
    
    }     
}
void ChessJudge::computeRookMovesVertical(int i, int j, int directionSign, ChessJudge::ValidMovesVector& validMoves){
    for(int k = i + directionSign; k != static_cast<int>(3.5 + directionSign*4.5); k = k + directionSign){
        if( board[k][j] == empty){
            addMove({k,j},validMoves);
        }
        else{ 
            if(std::abs(board[i][j] - board[k][j]) >= difference){
                isCheck(k,j);
                addMove({k,j},validMoves);
            }
            break;
        }
    }      
}

ChessJudge::ValidMovesVector ChessJudge::computePawnMoves(int i, int j){
    ValidMovesVector validMoves;
    switch (board[i][j])
    {
    case w_Pawn:
        computePawnMovesHelper(i,j,-1, validMoves);
        break;
    case b_Pawn:
        computePawnMovesHelper(i,j,+1, validMoves);
        break;
    default:
        break;
    }

    return validMoves;
}

void ChessJudge::computePawnMovesHelper(int i, int j, int dir, ValidMovesVector& validMoves){
    auto right = j + 1;
    auto left =  j - 1;
    auto next = i + dir;
    if(next < 8){
        if( board[next][j] == empty){
            addMove({next,j},validMoves);
            if( std::abs(i - 3.5 + 2.5*dir) < std::numeric_limits<double>::epsilon()){
                if(board[i + dir*2][j] == empty){
                    addMove({i + dir * 2,j},validMoves);
                }
            }
        }
        if(right < 8  && std::abs(board[next][right] - board[i][j]) >= difference){
            addMove({next,right},validMoves);
        }
        if(left > -1 && std::abs(board[next][left] - board[i][j]) >= difference){
            addMove({next,left},validMoves);
        }
    }
}

void ChessJudge::movePiece(std::pair<int, int> from, std::pair<int, int> to){
    board[to.first][to.second] = board[from.first][from.second];
    board[from.first][from.second] = empty;
    printBoard(board);
}


void ChessJudge::addMove(std::pair<int,int> ij, ValidMovesVector& validMoves){
    if(1){
        validMoves.push_back({ij});
    }
}

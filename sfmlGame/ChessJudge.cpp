#include "ChessJudge.hpp"
#include <iostream>
#include <iomanip>

ChessJudge::ChessJudge(){
    std::vector<c_Piece> vec0;
    std::vector<c_Piece> vec1;
    std::vector<c_Piece> vec6;
    std::vector<c_Piece> vec7;


    std::vector<c_Piece> vec8(8,static_cast<c_Piece>(0));

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

    // i = first
    // j = second    



    switch (board[from.second][from.first])
    {
    case w_Pawn:
        valid = valid || (from.second == 6 && from.second - to.second <= 2 && std::abs(from.first - to.first) == 0);
        valid = valid ||  from.second - to.second == 1 && std::abs(from.first - to.first) == 0;
        if(std::abs(from.first - to.first) == 1){
            if(board[to.second][to.first] > Black){
                valid = true;
            }
        }
        valid = valid && (from.second - to.second <= 2);
        break;
    default:
        valid = true;
        break;
    }



    if(valid){
        std::cout<<"is valid " << std::endl;
        board[to.second][to.first] = board[from.second][from.first];
        board[from.second][from.first] = static_cast<c_Piece>(0);
        printBoard(board);
        return true;
    }
    printBoard(board);
    return false;
    
}

#include "AbstractBoardModel.hpp"

AbstractBoardModel::AbstractBoardModel()
    :currPiece{nullptr}
{
    for(int i = 0; i < 8 ; ++i ){    
        std::vector<PiecePtr<>> vec(8);
        piecePtrVec.push_back(std::move(vec));
    }
}



void AbstractBoardModel::movePiece(int oldX, int oldY, int newX, int newY){

    piecePtrVec[oldX][oldY]->moveTo({newX, newY});
    piecePtrVec[newX][newY] = std::move(piecePtrVec[oldX][oldY]);
}

void AbstractBoardModel::addPiece(PiecePtr<> piece){
    piecePtrVec[piece->getXY().first][piece->getXY().second] = std::move(piece);
}

bool AbstractBoardModel::isValidMove(std::pair<int,int> from, std::pair<int, int> to){

    if(!piecePtrVec[to.first][to.second] && piecePtrVec[from.first][from.second]) {
        return piecePtrVec[from.first][from.second]->isValid(from,to);
    }
    else{
        return (piecePtrVec[from.first][from.second]->getColor() != piecePtrVec[to.first][to.second]->getColor() )
                      && piecePtrVec[from.first][from.second]->isValid(from, to) ;
    }
}

bool AbstractBoardModel::isSameColor(std::pair<int, int> from, std::pair<int, int> to){
    if( piecePtrVec[from.first][from.second]->getColor() != piecePtrVec[to.first][to.second]->getColor()){
        return false;
    }
    return true;

}

bool AbstractBoardModel::isValidCoordinate(int x, int y) { 
   if( x > 7 || y > 7){
      throw std::out_of_range{"x = " + std::to_string(x) + " y =  " + std::to_string(y)};
   } 
   return piecePtrVec[x][y].get();
}

bool AbstractBoardModel::isColor(Piece::Color color, int x, int y)
{
    if(isValidCoordinate(x,y)){
        if(piecePtrVec[x][y]->getColor() == color)
            return true;
        else {
            return false;
        }
    }
    return false;
}

bool AbstractBoardModel::isTurnOf(Piece::Color color){
    return color == turn;
}

void AbstractBoardModel::changeTurn()
{
    if(turn == Piece::Color::White){
        turn = Piece::Color::Black;
    }
    else{
        turn = Piece::Color::White;
    }
}

void AbstractBoardModel::setCurrPiece(int x, int y){
    currPiece = piecePtrVec[x][y].get();
}

void AbstractBoardModel::setCurrPiece(Piece *ptr){
    currPiece = ptr;
}

void AbstractBoardModel::setCheckedPiece(int x, int y){
    checkedPiece = piecePtrVec[x][y].get();
}

void AbstractBoardModel::resetChecking(){
    checkedPiece = nullptr;
}

void AbstractBoardModel::setValidMoves(std::vector<std::pair<int, int>> &&moves){
    validMoves = std::move(moves);
}

void AbstractBoardModel::setValidMoves(std::vector<std::pair<int, int>> &moves){
    validMoves = moves;
}

#include <iostream>
#include "AbstractBoardModel.hpp"
#include "CellSizeController.hpp"
#include "GameController.hpp"
#include "Mouse.hpp"

void GameController::handleEvents(Window &window, Event &event){
    static int x{};
    static int y{};
    static int count = 1;
    
    try{
        if(mouseButtons['l'].state.clicked){
        
            auto size = CellSizeController::getCellSize();
            if(count == 1  ){
                x = Mouse::getPosition(window).x/ size;
                y = Mouse::getPosition(window).y/ size;
                if(model->isValidCoordinate(x,y) && model->isTurnOf( model->getColor(x,y))){
                    --count;
                    model->setCurrPiece(x,y);
                    model->setValidMoves(judge.getValidMoves(y,x));
                }
            }
            else if(count == 0){
                auto newX = Mouse::getPosition(window).x / size;
                auto newY = Mouse::getPosition(window).y / size;
                if( model->isValidMove({x, y}, { newX , newY}) ){
                    if(std::find(model->getValidMoves().begin(), model->getValidMoves().end(), std::pair{newY, newX}) != model->getValidMoves().end() ){
                        model->movePiece(x, y, newX , newY );
                        judge.movePiece({y,x}, {newY,newX});
                        model->setCurrPiece(nullptr);
                        model->clearValidMoves();
                        model->changeTurn();
                        judge.changeTurn();
                        count = 1;
                    }
                }
                else if(model->isSameColor({x,y},{newX,newY})){
                    x = newX;
                    y = newY;
                    model->setCurrPiece(x,y);
                    model->clearValidMoves();
                    model->setValidMoves( judge.getValidMoves(y,x));
                }
            }
        }
    }
    catch(const std::exception& exception){
        std::cout << exception.what() << std::endl;
    }
}
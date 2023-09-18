#include "Controller.hpp"
#include "../AbstractBoardModel.hpp"
#include <iostream>

#include "Mouse.hpp"

void Controller::queryEvents(Window &window, Event &event){
    setFlags(window, event);

    
    static int x{};
    static int y{};
    static int count = 1;
try{
    if(mouseButtons['l'].state.clicked){

        if(count == 1  ){
            x = Mouse::getPosition(window).x/110;
            y = Mouse::getPosition(window).y/110;
            if(model->isValidCoordinate(x,y) && model->isTurnOf( model->getColor(x,y))){
                --count;
                model->setCurrPiece(x,y);
                auto moves = judge.getValidMoves(y,x);
                model->setValidMoves(std::move(moves));
                
            }
        }
        else if(count == 0){
            auto newX = Mouse::getPosition(window).x / 110;
            auto newY = Mouse::getPosition(window).y / 110;

            if( model->isValidMove({x, y}, { newX , newY}) && judge.isValid({y,x},{newY, newX}) ){
                model->movePiece(x, y, newX , newY );
                judge.movePiece({y,x}, {newY,newX});
                count = 1;
                model->setCurrPiece(nullptr);
                model->changeTurn();
                model->clearValidMoves();
            }
            else {
                x = newX;
                y = newY;
                model->setCurrPiece(x,y);
                model->clearValidMoves();
                auto moves = judge.getValidMoves(y,x);
                model->setValidMoves(std::move(moves));
            }
        }
        std::cout<<"count: " << count << std::endl;
    }
}
catch(const std::exception& exception){
    std::cout << exception.what() << std::endl;
}
}

void Controller::setModel(AbstractBoardModel *model_){
    model = model_;
}

void Controller::setFlags(Window &window, Event &event) { }
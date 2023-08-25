#include "Controller.hpp"
#include "../AbstractBoardModel.hpp"
#include <iostream>

#include "Mouse.hpp"

void Controller::queryEvents(Window &window, Event &event){
    setFlags(window, event);

    
    static int x{};
    static int y{};
    static int count = 1;

    if(mouseButtons['l'].state.clicked){

        if(count == 1  ){
            x = Mouse::getPosition(window).x/110;
            y = Mouse::getPosition(window).y/110;
            std::cout<<"choosed" << std::endl;
            if(model->isValidCoordinate(x,y) && model->isTurnOf( model->getColor(x,y))){
                --count;
                model->setCurrPiece(x,y);
            }
        }
        else if(count == 0){
            auto newX = Mouse::getPosition(window).x / 110;
            auto newY = Mouse::getPosition(window).y / 110;

            if( model->isValidMove({x, y}, { newX , newY}) && judge.isValid({x,y},{newX, newY}) ){
                model->movePiece(x, y, newX , newY );
                count = 1;
                model->setCurrPiece(nullptr);
                model->changeTurn();
            }
            else {
                x = newX;
                y = newY;
                model->setCurrPiece(x,y);
                count = 1;
            }
        }
        std::cout<<"count: " << count << std::endl;
    }
}

void Controller::setModel(AbstractBoardModel *model_){
    model = model_;
}

void Controller::setFlags(Window &window, Event &event) { }
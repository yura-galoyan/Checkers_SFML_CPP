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
            if (model->isValidCoordinate(x,y)){
                --count;
                model->setCurrPiece(x,y);
            }
            else {
                model->setCurrPiece(nullptr);
            }
        }
        else if(count == 0){
            model->movePiece(x, y, Mouse::getPosition(window).x / 110, Mouse::getPosition(window).y / 110 );
            count = 1;
        }
    }
}

void Controller::setModel(AbstractBoardModel *model_){
    model = model_;
}

void Controller::setFlags(Window &window, Event &event) { }
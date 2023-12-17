#include "MainGameController.hpp"
#include "../EventSystem/EventPoller.hpp"
#include "../System/Mouse.hpp"
#include "../Constants/BoardConstants.hpp"
#include <iostream>

MainGameController::MainGameController(EventPoller* eventPoller, std::unique_ptr<ApplicationProtocol> clientServer,
                                        Player player1, Player player2)
    :iController(eventPoller), m_clientServer{std::move(clientServer)},player1{player1}, player2{player2}
{
    
}

void MainGameController::handleEvents(Window &window)
{
    m_eventPoller->setFlags(window);
    m_pWindow = &window;
    handleMessages();
}

void MainGameController::handleMessages(){
    if( m_clientServer->isConnected()){
        while(!m_clientServer->incoming().empty())
        {
            auto msg = m_clientServer->incoming().pop_front().msg;
            switch (msg.header.id)
            {
            case CheckersMsgType::ServerAccept:

                break;
            case CheckersMsgType::Assign_id:
            
                break;
            case CheckersMsgType::OtherPlayer:
                break;

            case CheckersMsgType::PlayerMove1:
            {
                
            }
            break;

            case CheckersMsgType::PlayerMove:
                {
                    Vector2i newFrom;
                    Vector2i newTo;

                    msg >> newTo;
                    msg >> newFrom;

                    std::cout << "new to x y" << newTo.x << " " << newTo.y 
                              << " | new from  x y" << newFrom.x << " " << newFrom.y << std::endl;

                    std::cout << "received moving message" << std::endl;
                    if(m_spModel->tryToMove(newFrom,newTo)){
                        std::cout << "Move succesfully completed." << std::endl;
                    }
                }
                break;
            case CheckersMsgType::PlayerMove2:
            {
                
            }
                break;
            default:
                std::cout << "Undefined message type" << std::endl;
                break;
            }
        }
    }
}

void MainGameController::sendMoveMessage(Vector2i from, Vector2i to){
    Ynet::Message<CheckersMsgType> msg;
    msg.header.id = CheckersMsgType::PlayerMove;
   
    msg << from;
    msg << to;
    m_clientServer->send(msg);
};


void MainGameController::onLeftClickEvent(){
    auto pos = Mouse::getPosition(*m_pWindow);
    int i{-1},j{-1};
        // adjust for window size
    if(player1.id == 1){
        j = (pos.x - BOARD_POS_X) / dynCellSize;
        i = (pos.y - BOARD_POS_Y) / dynCellSize;
    }
    else if(player1.id == 2){
        j = 7 - ((pos.x - BOARD_POS_X )/ dynCellSize);
        i = 7 - ((pos.y - BOARD_POS_Y )/ dynCellSize);
    }
    std::cout << "count = " << count << std::endl;
    if(count == 0){
        from = {j,i};
        ++count;

        if( m_spModel->isEmpty(from)){
            std::cout << "is empty because --- ";
            std::cout << "i: "  << i 
                      << " j: " << j << std::endl;
            count == 0;
        }
        else{
            std::cout << "picked a piece" << std::endl;
        }
    }
    else if(count == 1){
        to = {j,i};
        std::cout << "trying to move..." << std::endl;
        if(!m_spModel->isEmpty(to)){
           
        }
        else{
            if(m_spModel->tryToMove(from,to)){
                std::cout << "moving a piece" << std::endl;
                /// sending s message
                sendMoveMessage(from,to);
                count = 0;
            }
            else{
                
            };
            
        }

    }

};




void MainGameController::onLeftDoubleClickEvent(){

};

void MainGameController::onRightClickEvent(){

};

void MainGameController::onRightDoubleClickEvent(){

};

void MainGameController::onLeftHoldEvent(){

};

void MainGameController::onRightHoldEvent(){

};

void MainGameController::onLeftMoveEvent(){

};

void MainGameController::onRightMoveEvent(){

}


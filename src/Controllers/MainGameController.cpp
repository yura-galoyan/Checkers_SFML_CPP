#include "MainGameController.hpp"
#include "../EventSystem/EventPoller.hpp"
#include "../System/Mouse.hpp"
#include "../Constants/BoardConstants.hpp"


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


void MainGameController::onLeftClickEvent(){
    auto pos = Mouse::getPosition(*m_pWindow);

    int i{-1},j{-1};
    std::cout << "x: " << pos.x << " y: " << pos.y << std::endl;
    std::cout<< "window: " << m_pWindow->getSize().first << " " << m_pWindow->getSize().second << std::endl; 
// adjust for window size
    if(player1.id == 1){
        i = (pos.x - BOARD_POS_X) / dynCellSize;
        j = (pos.y - BOARD_POS_Y) / dynCellSize;
    }
    else if(player1.id == 2){
        i = 7 - ((pos.x - BOARD_POS_X )/ dynCellSize);
        j = 7 - ((pos.y - BOARD_POS_Y )/ dynCellSize);
    }

    std::cout << "i: " << i << " j: " << j << std::endl; 
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

};



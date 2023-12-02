#include "MainGameController.hpp"
#include "../EventSystem/EventPoller.hpp"

MainGameController::MainGameController(EventPoller* eventPoller, std::unique_ptr<ApplicationProtocol> clientServer,
                                        Player player1, Player player2)
    :iController(eventPoller), m_clientServer{std::move(clientServer)},player1{player1}, player2{player2}
{
    
}

void MainGameController::handleEvents(Window &window)
{
    m_eventPoller->setFlags(window);
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



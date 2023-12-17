#include "GameLobbyController.hpp"
#include <iostream>
#include "../EventSystem/EventPoller.hpp"

GameLobbyController::GameLobbyController(EventPoller* eventPoller)
    :iController(eventPoller)
{
}

void GameLobbyController::onLoad()
{
    std::cout << "Starting Game Lobby!!!" << std::endl;
    clientServer = std::make_unique<ApplicationProtocol>();

    if( clientServer->connect("127.0.0.1", 60000)){
        std::cout << "Server is found!!" << std::endl;
    }
    else{
        std::cout << "No such Server!!" << std::endl;
    }
}


void GameLobbyController::handleEvents(Window &window)
{
    m_eventPoller->setFlags(window);
    registerToServer();

    if(!bIsGameReady){
        if(player1.id == 1){
            std::cout << "i am the first player" << std::endl;
        };
        if(player1.id == 2){
            bIsGameReady = true;
            std::cout << "i am the second player" << std::endl;
        };
    }
        
}

bool GameLobbyController::isGameReady(){
    return bIsGameReady;
}

void GameLobbyController::registerToServer()
{
    if( clientServer->isConnected()){
        while(!clientServer->incoming().empty())
        {
            auto msg = clientServer->incoming().pop_front().msg;
            switch (msg.header.id)
            {
            case CheckersMsgType::ServerAccept:
                std::cout << "Server accepted player" << std::endl;
                break;
            case CheckersMsgType::Assign_id:
                std::cout << "accepting data" << std::endl;
                msg >> player1;
                std::cout << "Your info id is: " << player1.id;
                if(player1.color == Color::White){
                    std::cout <<  "\nColor: white";
                }
                else{
                    std::cout << "\ncolor: black" << std::endl; 
                }

                if(player1.id == 2){
                    bIsGameReady = true;
                    player2.id = 1;
                    player2.color = Color::White;
                }

                break;
            case CheckersMsgType::OtherPlayer:
                {
                    msg >> player2;

                    std::cout << player2.id << "-nd is ready" << std::endl;
                    bIsGameReady = true;
                }
                break;
            default:
                std::cout << "Undefined message type" << std::endl;
                break;
            }
        }

        }
}
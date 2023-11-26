#include "GameLobbyState.hpp"

GameLobbyState::GameLobbyState(Application* app,TextureHolderPtr textures, FontsHolderPtr fonts, Window& window, EventPoller* eventPoller)
    : m_app{app},
    iGameState(
            std::make_unique<GameLobbyController>(eventPoller),
            std::make_unique<GameLobbyView>(std::move(textures), std::move(fonts)),
            &window
        )
{
    m_view->init();
};

void GameLobbyState::start()
{
    std::cout << "Starting Game Lobby!!!" << std::endl;
    clientServer = std::make_unique<ApplicartionProtocol>();

    if( clientServer->connect("127.0.0.1", 60000)){
        std::cout << "Server is found!!" << std::endl;
    }
    else{
        std::cout << "No such Server!!" << std::endl;
    }


    while(m_window->isOpen()){
        m_controller->handleEvents(*m_window);
        registerToServer();
        m_window->clear();
        m_view->render(*m_window);
        m_window->display();
    }
}

void GameLobbyState::registerToServer()
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

                break;
            default:
                std::cout << "Undefined message type" << std::endl;
                break;
            }
        }

        }
}

#ifndef STATES_GAME_LOBBY_STATE_HPP
#define STATES_GAME_LOBBY_STATE_HPP

#include "iGameState.hpp"

#include "../ApplicartionProtocol.hpp"
#include "../Board/BackGround.hpp"
#include "../Ynet/Client.hpp"
#include "../Controllers/GameLobbyController.hpp"
#include "../Views/GameLobbyView.hpp"

class GameLobbyState : public iGameState
{
public:
    GameLobbyState(Application* app, TextureHolderPtr textures, FontsHolderPtr fonts, Window& window, EventPoller* eventPoller);

    void start() override;
    void registerToServer();
    
private:
    // backward connect to m_app for changing the state
    Application* m_app;
   
   Player player1{0,Color::None};
   Player player2{0,Color::None};
   // client server stuff

    std::unique_ptr<ApplicartionProtocol> clientServer;

    



};

#endif //STATES_GAME_LOBBY_STATE_HPP
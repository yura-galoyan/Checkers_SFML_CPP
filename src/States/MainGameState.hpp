#ifndef STATES_MAIN_GAME_STATE_HPP
#define STATES_MAIN_GAME_STATE_HPP

#include <memory>

#include "iGameState.hpp"
#include "../ApplicationProtocol.hpp"
class MainGameState : public iGameState
{
public:
    MainGameState(Application* app,  TextureHolderPtr textures,
                  FontsHolderPtr fonts, Window& window,
                  EventPoller* eventPoller, std::unique_ptr<ApplicationProtocol> clientServer, 
                  Player player1, Player player2);

    
    void start() override;


private:
    Application* m_app;
};


#endif //STATES_MAIN_GAME_STATE_HPP
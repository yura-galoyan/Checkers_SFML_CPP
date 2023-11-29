#ifndef CONTROLLERS_MAIN_GAME_CONTROLLER_HPP
#define CONTROLLERS_MAIN_GAME_CONTROLLER_HPP

#include "iController.hpp"
#include "../ApplicationProtocol.hpp"
#include "../../Common/Common.hpp"
class MainGameController : public iController
{
public:
    MainGameController(EventPoller* eventPoller, std::unique_ptr<ApplicationProtocol> clientServer,
                        Player player1, Player player2  );

    void handleEvents(Window& window) override;
    void handleMessages();
    
private:
    std::unique_ptr<ApplicationProtocol> m_clientServer;

    Player player1;
    Player player2;

};



#endif //CONTROLLERS_MAIN_GAME_CONTROLLER_HPP
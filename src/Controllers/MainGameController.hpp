#ifndef CONTROLLERS_MAIN_GAME_CONTROLLER_HPP
#define CONTROLLERS_MAIN_GAME_CONTROLLER_HPP

#include "../ApplicationProtocol.hpp"
#include "../Board/RegularBoardModel.hpp"
#include "../../Common/Common.hpp"
#include "iController.hpp"
class MainGameController : public iController
{
public:
    MainGameController(EventPoller* eventPoller, std::unique_ptr<ApplicationProtocol> clientServer,
                        Player player1, Player player2  );

    void handleEvents(Window& window) override;
    void handleMessages();
    void closeConnection() {
        m_clientServer->disconnect();
        Ynet::Message<CheckersMsgType> msg;
        msg.header.id = CheckersMsgType::MessageAll;
        msg << 5;
        m_clientServer->send(msg);
    };


    void setModel(std::shared_ptr<RegularBoardModel> model){m_spModel = model; }



public:
    void onLeftClickEvent() override;
    void onLeftDoubleClickEvent() override;
    void onRightClickEvent() override;
    void onRightDoubleClickEvent() override;
    void onLeftHoldEvent() override;
    void onRightHoldEvent() override;
    void onLeftMoveEvent() override;
    void onRightMoveEvent() override;

private:
    std::unique_ptr<ApplicationProtocol> m_clientServer;
    std::shared_ptr<RegularBoardModel> m_spModel;

    Player player1;
    Player player2;

};



#endif //CONTROLLERS_MAIN_GAME_CONTROLLER_HPP
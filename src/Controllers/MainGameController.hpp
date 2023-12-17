#ifndef CONTROLLERS_MAIN_GAME_CONTROLLER_HPP
#define CONTROLLERS_MAIN_GAME_CONTROLLER_HPP

#include "../ApplicationProtocol.hpp"
#include "../Board/RegularBoardModel.hpp"
#include "../../Common/Common.hpp"
#include "../System/Window.hpp"
#include "iController.hpp"
class MainGameController : public iController
{
public:
    MainGameController(EventPoller* eventPoller, std::unique_ptr<ApplicationProtocol> clientServer,
                        Player player1, Player player2  );

    void handleEvents(Window& window) override;
    void handleMessages();
    void closeConnection() { 
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
    void sendMoveMessage(Vector2i from, Vector2i to);

private:
    std::unique_ptr<ApplicationProtocol> m_clientServer;
    std::shared_ptr<RegularBoardModel> m_spModel;
    Window* m_pWindow;
    Player player1;
    Player player2;


private:
    int dynCellSize{110};
    int count{};
    Vector2i from;
    Vector2i to;


};



#endif //CONTROLLERS_MAIN_GAME_CONTROLLER_HPP
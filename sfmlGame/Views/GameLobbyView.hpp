#ifndef GAME_LOBBY_VIEW_HPP
#define GAME_LOBBY_VIEW_HPP

#include "iView.hpp"
#include "../Board/BackGround.hpp"
#include "System/Text.hpp"


class GameLobbyView : public iView
{
public:
    GameLobbyView(TextureHolderPtr textures, FontHolderPtr fonts); 
    void render(Window& window) override ;
    void init() override;

private:
    Text PlayerHud1;
    Text PlayerHud2;
    BackGround m_background;
};


#endif //GAME_LOBBY_VIEW_HPP
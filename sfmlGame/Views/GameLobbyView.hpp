#ifndef GAME_LOBBY_VIEW_HPP
#define GAME_LOBBY_VIEW_HPP

#include "iView.hpp"
#include "../Board/BackGround.hpp"

class GameLobbyView : public iView
{
public:
    GameLobbyView(TextureHolder textures); 
    void render(Window& window) override ;

private:
    BackGround m_background;
};


#endif //GAME_LOBBY_VIEW_HPP
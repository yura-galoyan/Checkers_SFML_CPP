#ifndef GAME_LOBBY_VIEW_HPP
#define GAME_LOBBY_VIEW_HPP

#include "iView.hpp"
#include "../Board/BackGround.hpp"
#include "../System/Text.hpp"
#include <cstdint>

class GameLobbyView : public iView
{
public:
    GameLobbyView(TextureHolderPtr textures, FontsHolderPtr fonts); 
    void render(Window& window) override ;
    void init() override;
    void setReady(std::uint16_t id, bool state);
private:
    Text m_playerHud1;
    Text m_playerHud2;
    BackGround m_background;
};


#endif //GAME_LOBBY_VIEW_HPP
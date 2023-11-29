#ifndef VIEWS_MAIN_GAME_VIEW_HPP
#define VIEWS_MAIN_GAME_VIEW_HPP

#include "iView.hpp"

#include "../Board/BackGround.hpp"
#include "../System/Text.hpp"
class MainGameView : public iView
{
public:
    MainGameView(TextureHolderPtr textures, FontsHolderPtr fonts); 
    void render(Window& window) override;
    void init(int id) override;
    
private:
    BackGround m_background;
    Text m_playerHud1;
    Text m_playerHud2;

};


#endif //VIEWS_MAIN_GAME_VIEW_HPP
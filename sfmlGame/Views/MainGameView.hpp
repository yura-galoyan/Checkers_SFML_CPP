#ifndef VIEWS_MAIN_GAME_VIEW_HPP
#define VIEWS_MAIN_GAME_VIEW_HPP

#include "iView.hpp"

class MainGameView : public iView
{
public:
    MainGameView(TextureHolder textures); 
    void render(Window& Window) override;

private:
    
};


#endif //VIEWS_MAIN_GAME_VIEW_HPP
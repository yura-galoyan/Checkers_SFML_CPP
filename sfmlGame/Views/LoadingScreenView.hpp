#ifndef VIEWS_LOADING_SCREEN_VIEW_HPP
#define VIEWS_LOADING_SCREEN_VIEW_HPP

#include "iView.hpp"

#include "../System/AnimationHandler.hpp"
#include "../System/TextureManager.hpp"
#include "../System/Sprite.hpp"

class LoadingScreenView : public iView
{
public:
    LoadingScreenView(TextureHolder textures); 
    void render(Window& window) override;

public:
    void init() override;


private:
    AnimationHandler loadingIconAnimation; 
    Sprite loadingIconSprite;
    Sprite title;
};


#endif //VIEWS_LOADING_SCREEN_VIEW_HPP
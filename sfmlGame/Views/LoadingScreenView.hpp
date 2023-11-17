#ifndef VIEWS_LOADING_SCREEN_VIEW_HPP
#define VIEWS_LOADING_SCREEN_VIEW_HPP

#include "iView.hpp"

#include "../System/AnimationHandler.hpp"
#include "../System/TextureManager.hpp"
#include "../System/Sprite.hpp"

class LoadingScreenView : public iView
{
public:
    void render(Window& window) override;

public:
    void init() override;

private:
    void initLoadingTextures();
    

private:
    AnimationHandler loadingIconAnimation;
    TextureManager texManager;
    Sprite loadingIconSprite;
    TextureLoader loader;
    Sprite background;
    
};


#endif //VIEWS_LOADING_SCREEN_VIEW_HPP
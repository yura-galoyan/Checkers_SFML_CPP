#include "LoadingScreenView.hpp"

void LoadingScreenView::render(Window &window)
{
    background.draw(window);
    loadingIconSprite.draw(window);
}

void LoadingScreenView::init()
{
    // initializing title
    background.setPosition(0,0);
    background.setTexture(&texManager["loading_screen_title"]);

    /// TODO: "Magic numbers" are EVIL, need to do something about this!!! 
    loadingIconSprite.setStartingRect({1,1},{58,58});
    loadingIconSprite.setTexture(&texManager["loading_screen_icon_sheet"]);
    loadingIconSprite.setPosition(0,0);

    loadingIconAnimation = AnimationHandler{&loadingIconSprite,loadingIconSprite.getSize().x,loadingIconSprite.getSize().y};
    loadingIconAnimation.setDesiredFps(30);
    loadingIconAnimation.setFrameCount(6);
    loadingIconAnimation.setDelayBetweenFrames(0.1f);
}

void LoadingScreenView::initLoadingTextures(){
    texManager.addTexture("loading_screen_title","../assets/LoadingScreen/checkers_title_curve.png" );
    texManager.addTexture("loading_screen_icon_sheet", "../assets/LoadingScreen/loading_icon_sheet.png" );
}
#include "LoadingScreenView.hpp"

LoadingScreenView::LoadingScreenView(TextureHolderPtr textures)
    : iView{std::move(textures)}
{
}

void LoadingScreenView::render(Window &window)
{
    
    title.draw(window);
    loadingIconSprite.draw(window);
}

void LoadingScreenView::init()
{
    const std::string loadingScreenPath = "../assets/LoadingScreen/";
    m_textures->load(TextureId::checkers_title_curve, loadingScreenPath + "checkers_title_curve.png");
    m_textures->load(TextureId::loading_icon_sheet, loadingScreenPath + "loading_icon_sheet.png");



    // initializing title
    title.setPosition(0,0);
    title.setTexture(&m_textures->get(TextureId::checkers_title_curve));

    
    /// TODO: "Magic numbers" are EVIL, need to do something about this!!! what is even this "58" thing
    loadingIconSprite.setStartingRect({1,1},{58,58});
    loadingIconSprite.setTexture(&m_textures->get(TextureId::loading_icon_sheet));
    loadingIconSprite.setPosition(0,0);

    loadingIconAnimation = AnimationHandler{&loadingIconSprite,loadingIconSprite.getSize().x,loadingIconSprite.getSize().y};
    loadingIconAnimation.setDesiredFps(30);
    loadingIconAnimation.setFrameCount(6);
    loadingIconAnimation.setDelayBetweenFrames(0.1f);
}

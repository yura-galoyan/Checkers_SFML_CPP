#ifndef STATES_LOADING_SCREEN_STATE_HPP
#define STATES_LOADING_SCREEN_STATE_HPP

#include "iGameState.hpp"

#include "../System/AnimationHandler.hpp"
#include "../System/TextureManager.hpp"
#include "../System/Window.hpp"
#include "../System/Sprite.hpp"


class LoadingScreenState : public iGameState
{
public:
    LoadingScreenState(Application* app, Window& window, Event& event);

    void start() override;

    std::atomic<bool>& isDone() { return done; }
    void finish( ) { done = true; }
    void draw(Window& window);
    void initSprite();

    Texture& getTexture(std::string key){ return texManager[key]; }

private:
    std::unique_ptr<AnimationHandler> animation;
    std::atomic<bool> done{false};
    TextureManager texManager;
    Application* m_app;
    Sprite sprite;
};


#endif //STATES_LOADING_SCREEN_STATE_HPP
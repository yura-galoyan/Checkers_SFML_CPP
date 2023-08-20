#ifndef LOADING_SCREEN_HPP
#define LOADING_SCREEN_HPP

#include "System/TextureManager.hpp"
#include "System/Controller.hpp"
#include "System/Sprite.hpp"
#include "System/Window.hpp"
#include "System/Event.hpp"

#include "AnimationHandler.hpp"

#include <atomic>
#include <memory>

class LoadingScreen
{
public:
    LoadingScreen();
    void start(Controller& , Window& , Event& );
    std::atomic<bool>& isDone() { return done; }
    void finish( ) { done = true; }
    void draw(Window& window);
    void initSprite();

    Texture& getTexture(std::string key){ return texManager[key]; }

private:
    std::unique_ptr<AnimationHandler> animation;
    TextureManager texManager;
    Sprite sprite;
    std::atomic<bool> done{false};
};

#endif //LOADING_SCREEN_HPP



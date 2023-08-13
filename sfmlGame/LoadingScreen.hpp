#ifndef LOADING_SCREEN_HPP
#define LOADING_SCREEN_HPP

#include "Controller.hpp"
#include "TextureManager.hpp"

#include "Window.hpp"
#include "Event.hpp"

#include <atomic>
class LoadingScreen
{
public:
    void start(Controller& , Window& , Event& );
    std::atomic<bool>& isDone() { return done; }
    void finish( ) { done = false; }
    void draw(Window& window);
    void initSprite();

private:
    TextureManager texManager;
    Sprite sprite;    
    std::atomic<bool> done{false};
};

#endif //LOADING_SCREEN_HPP
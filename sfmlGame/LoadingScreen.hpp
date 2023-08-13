#ifndef LOADING_SCREEN_HPP
#define LOADING_SCREEN_HPP

#include "Controller.hpp"
#include "Texture.hpp"
#include "Window.hpp"
#include "Event.hpp"

#include <atomic>
class LoadingScreen
{
public:
    void start(Controller& , Window& , Event& );
    void loadTextures();
    std::atomic<bool>& isDone() { return done; }
    void finish( ) { done = false; }

private:    
    std::atomic<bool> done{false};
};

#endif //LOADING_SCREEN_HPP
#ifndef ANIMATION_HANDLER_HPP
#define ANIMATION_HANDLER_HPP

#include "System/Texture.hpp"

class AnimationHandler
{
public:
    enum class Mode{ REPEAT, SINGLE };

public:
    AnimationHandler( Texture* texture, unsigned height, unsigned width  );
    void setFrameCount(unsigned count);
    void setBlockingAnimation(bool state);
    void setAnimationDuration(float duration);
    void setDelayBetweenFrames(float delay);
    void setDesiredFps(unsigned fps_);
    void setTexture(Texture* tex);
    void playAnimation(Mode);


private:
    void playAnimationOnce();
    void playAnimationRepeat();

    float elapsed();
    bool isStart;


private:
    Texture* texture;
    unsigned fps;
    unsigned frameCount;
    float delayBetweenFrames;
    float animationDuration;
    bool blockingAnimation;

    

private:
    std::chrono::time_point<float> start;
    std::chrono::time_point<float> end;


};



#endif //ANIMATION_HANDLER_HPP

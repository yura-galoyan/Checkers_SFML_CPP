#ifndef ANIMATION_HANDLER_HPP
#define ANIMATION_HANDLER_HPP


#include "System/Sprite.hpp"
#include "System/Clock.hpp"


class AnimationHandler
{
public:
    enum class Mode{ REPEAT, SINGLE };

public:
    AnimationHandler( Sprite* sprite, unsigned height, unsigned width  );
    void setFrameCount(unsigned count);
    void setBlockingAnimation(bool state);
    void setAnimationDuration(float duration);
    void setDelayBetweenFrames(float delay);
    void setDesiredFps(unsigned fps_);
    void setSprite(Sprite* spr);

    void playAnimation(Mode);

private:
    void playAnimationOnce();
    void playAnimationRepeat();
    bool isStarted;

private:
    Sprite* sprite;

private:
    unsigned fps;
    unsigned frameCount;
    float delayBetweenFrames;
    float animationDuration;
    bool blockingAnimation;

private:
    unsigned currFrame{};

private:
    Clock<float> clock;
    float time{};

};



#endif //ANIMATION_HANDLER_HPP





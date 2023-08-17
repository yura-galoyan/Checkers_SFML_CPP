#include "AnimationHandler.hpp"

#include <chrono>

AnimationHandler::AnimationHandler(Sprite* sprite, unsigned height, unsigned width)
    :sprite{sprite}, blockingAnimation{false}, animationDuration{1.5f}, delayBetweenFrames{0.1f} ,fps{30}
{
    
}


void AnimationHandler::playAnimation(Mode mode){
    if(mode == Mode::SINGLE){
        playAnimationOnce();
    }
    else if(mode == Mode::REPEAT){
        playAnimationRepeat();
    }
}

void AnimationHandler::setSprite(Sprite* sprite_){
    sprite = sprite_;
}

void AnimationHandler::playAnimationOnce(){

}


void AnimationHandler::playAnimationRepeat(){

    auto dt = clock.restart();
    time += dt;
    if(time > delayBetweenFrames){

        sprite->setCurrRectPosX(sprite->getStartingRectPos().x + sprite->getDistanceX() * currFrame);
        ++currFrame;
        if(currFrame > frameCount){
            currFrame  = 1;
            sprite->setCurrRectPosX(sprite->getStartingRectPos().x);
            sprite->setCurrRectPosY(sprite->getStartingRectPos().y);
        }

        time = 0.f;
    }
}

void AnimationHandler::setFrameCount(unsigned count){
    this->frameCount = count; 
}

void AnimationHandler::setBlockingAnimation(bool state){
    this->blockingAnimation = state;
}

void AnimationHandler::setAnimationDuration(float duration){
    this->animationDuration = duration;
}

void AnimationHandler::setDelayBetweenFrames(float delay){
    this->delayBetweenFrames = delay;
}

void AnimationHandler::setDesiredFps(unsigned fps_){
    this->fps = fps_;
}


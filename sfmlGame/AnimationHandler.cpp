#include "AnimationHandler.hpp"

#include <chrono>

AnimationHandler::AnimationHandler(Texture* texture, unsigned height, unsigned width)
    :texture{texture}, blockingAnimation{false}, animationDuration{1.5f}, delayBetweenFrames{0.1f} ,fps{30}
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

void AnimationHandler::setTexture(Texture *tex){
    texture = tex;
}

void AnimationHandler::playAnimationOnce(){

}

float AnimationHandler::elapsed(){
    
}


void AnimationHandler::playAnimationRepeat(){

    



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


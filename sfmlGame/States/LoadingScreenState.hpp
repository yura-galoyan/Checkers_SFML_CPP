#ifndef STATES_LOADING_SCREEN_STATE_HPP
#define STATES_LOADING_SCREEN_STATE_HPP

#include "iGameState.hpp"

#include "../System/Window.hpp"


class LoadingScreenState : public iGameState
{
public:
    LoadingScreenState(Application* app, TextureHolderPtr textures, Window& window, EventPoller* eventPoller);

    void start() override;


public:
    void initGameTextures(TextureHolder& textureHolder);

private:
    Application* m_app;
};


#endif //STATES_LOADING_SCREEN_STATE_HPP
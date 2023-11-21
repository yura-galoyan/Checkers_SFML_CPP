#include "GameLobbyView.hpp"

GameLobbyView::GameLobbyView(TextureHolderPtr textures)
    : iView{std::move(textures)}
{
}

void GameLobbyView::render(Window &window)
{
    m_background.draw(window);
}

void GameLobbyView::init()
{
    /// implement
}

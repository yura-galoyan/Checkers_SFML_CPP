#include "GameLobbyView.hpp"

GameLobbyView::GameLobbyView(TextureHolderPtr textures, FontHolderPtr fonts)
    : iView{std::move(textures), std::move(fonts)}
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

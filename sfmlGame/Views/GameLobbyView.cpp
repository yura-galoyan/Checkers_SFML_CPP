#include "GameLobbyView.hpp"

GameLobbyView::GameLobbyView(TextureHolder textures)
    : iView{std::move(textures)}
{
}

void GameLobbyView::render(Window &window)
{
    m_background.draw(window);
}
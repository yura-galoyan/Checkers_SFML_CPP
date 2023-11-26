#include "GameLobbyView.hpp"

GameLobbyView::GameLobbyView(TextureHolderPtr textures, FontsHolderPtr fonts)
    : iView{std::move(textures), std::move(fonts)}
{
}

void GameLobbyView::render(Window &window)
{
    m_background.draw(window);
}

void GameLobbyView::init()
{
    m_playerHud1.setFont(&m_fonts->get(FontId::player_hud));
    m_playerHud1.setText("Player 1 waiting connection...");
    m_playerHud1.setPosition({10.f,10.f});


    m_playerHud2.setFont(&m_fonts->get(FontId::player_hud));
    m_playerHud2.setText("Player 2 waiting connection...");
    m_playerHud2.setPosition({10.f, 850.f});




}

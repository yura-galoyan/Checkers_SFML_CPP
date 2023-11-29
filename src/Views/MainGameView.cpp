#include "MainGameView.hpp"

#include "../Constants/BoardConstants.hpp"

MainGameView::MainGameView(TextureHolderPtr textures, FontsHolderPtr fonts)
    : iView{std::move(textures), std::move(fonts)}
{
}

void MainGameView::render(Window &window)
{
    m_background.draw(window);
}

void MainGameView::init(int id)
{
if(id == 1){

}
else if(id == 2){
    
}
    m_background.setPosition(BOARD_POS_X, BOARD_POS_Y);
    m_background.setTexture(&m_textures->get(TextureId::checkers_black_white_cells));
    m_background.initSprites();

    m_playerHud1.setFont(&m_fonts->get(FontId::player_hud));
    m_playerHud1.setText("Player 1");
    m_playerHud1.setPosition({10.f,10.f});
    m_playerHud1.setCharacterSize(20);

    m_playerHud2.setFont(&m_fonts->get(FontId::player_hud));
    m_playerHud2.setText("Player 2");
    m_playerHud2.setPosition({10.f, static_cast<float>(BOARD_POS_Y + CELL_SIZE * 8 + 10)});
    m_playerHud2.setCharacterSize(20);

    // board->render
}
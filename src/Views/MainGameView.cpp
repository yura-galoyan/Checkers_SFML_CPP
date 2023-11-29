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

void MainGameView::init()
{
    m_background.setPosition(BOARD_POS_X, BOARD_POS_Y);
    m_background.setTexture(&m_textures->get(TextureId::checkers_black_white_cells));
    m_background.initSprites();

    // init HUDs


}

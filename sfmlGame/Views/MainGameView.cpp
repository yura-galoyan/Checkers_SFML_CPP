#include "MainGameView.hpp"

MainGameView::MainGameView(TextureHolderPtr textures, FontsHolderPtr fonts)
    : iView{std::move(textures), std::move(fonts)}
{
}

void MainGameView::render(Window &Window)
{
}

void MainGameView::init()
{
    /// implement
}

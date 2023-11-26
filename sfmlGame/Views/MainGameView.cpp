#include "MainGameView.hpp"

MainGameView::MainGameView(TextureHolderPtr textures)
    : iView{std::move(textures), nullptr}
{
}

void MainGameView::render(Window &Window)
{
}

void MainGameView::init()
{
    /// implement
}

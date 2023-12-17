#ifndef VIEWS_MAIN_GAME_VIEW_HPP
#define VIEWS_MAIN_GAME_VIEW_HPP

#include "iView.hpp"
#include "../Board/RegularBoardView.hpp"
#include "../Board/BackGround.hpp"
#include "../System/Text.hpp"
class MainGameView : public iView
{
public:
    MainGameView(TextureHolderPtr textures, FontsHolderPtr fonts); 
    void render(Window& window) override;
    void init(int id) override;
    void setModel(std::shared_ptr<RegularBoardModel> model){m_spModel = model; }
    
private:
    BackGround m_background;
    Text m_playerHud1;
    Text m_playerHud2;

private:
    void fillModel();
    void initPiece( Piece *piecePtr, int i, int j,Piece::Color color);

private:
    std::unique_ptr<iBoardView> m_boardView;
    std::shared_ptr<RegularBoardModel> m_spModel;
};


#endif //VIEWS_MAIN_GAME_VIEW_HPP
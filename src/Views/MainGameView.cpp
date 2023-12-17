#include "MainGameView.hpp"

#include "../Constants/BoardConstants.hpp"

#include "../Board/RegularBoardView.hpp"
#include "../Board/UpsideDownBoardView.hpp"
#include "../Pieces/Pawn.hpp"


MainGameView::MainGameView(TextureHolderPtr textures, FontsHolderPtr fonts)
    : iView{std::move(textures), std::move(fonts)}
{
}

void MainGameView::render(Window &window)
{
    m_playerHud1.draw(window);
    m_playerHud2.draw(window);
    m_background.draw(window);
    m_boardView->draw(window);


}

void MainGameView::init(int id)
{

    if(m_spModel){
        std::cout << "model is allocated" << std::endl;
    }
    fillModel();
    if(id == 1){
        std::cout << "creating view 1" << std::endl;
        m_boardView = std::make_unique<RegularBoardView>();

        m_playerHud1.setPosition({ 10.f,10.f });
        m_playerHud2.setPosition({ 10.f, static_cast<float>(BOARD_POS_Y + CELL_SIZE * 8 + 10) });
    }
    else if(id == 2){
        std::cout << "creating view 2" << std::endl;
        m_boardView = std::make_unique<UpsideDownBoardView>();

        m_playerHud2.setPosition({ 10.f,10.f });
        m_playerHud1.setPosition({ 10.f, static_cast<float>(BOARD_POS_Y + CELL_SIZE * 8 + 10) });

    }
    
    m_boardView->setModel(m_spModel);

    m_background.setPosition(BOARD_POS_X, BOARD_POS_Y);
    m_background.setTexture(&m_textures->get(TextureId::checkers_black_white_cells));
    m_background.initSprites();

    m_playerHud1.setFont(&m_fonts->get(FontId::player_hud));
    m_playerHud1.setText("Player 1");
    m_playerHud1.setCharacterSize(20);

    m_playerHud2.setFont(&m_fonts->get(FontId::player_hud));
    m_playerHud2.setText("Player 2");
    m_playerHud2.setCharacterSize(20);

    // board->render
}

void MainGameView::fillModel()
{



    for(int i = 0; i < 3; i+=2)
        for(int j = 1; j < 8; j+=2){      
            auto piecePtr = std::make_unique<Pawn>();
            initPiece(piecePtr.get(), i,j,Piece::Color::White);
            m_spModel->addPiece(std::move(piecePtr));
        }
    
    for(int j = 0; j < 8; j+=2){      
        auto piecePtr = std::make_unique<Pawn>();
        initPiece(piecePtr.get(), 1,j,Piece::Color::White);
        m_spModel->addPiece(std::move(piecePtr));
    }

    for(int i = 5; i < 8; i+=2)
        for(int j = 0; j < 8; j+=2){      
            auto piecePtr = std::make_unique<Pawn>();
            initPiece(piecePtr.get(), i,j,Piece::Color::Black);
            m_spModel->addPiece(std::move(piecePtr));
        }

    for(int j = 1; j < 8; j+=2){      
        auto piecePtr = std::make_unique<Pawn>();
        initPiece(piecePtr.get(), 6,j,Piece::Color::Black);
        m_spModel->addPiece(std::move(piecePtr));
    }   
}

void MainGameView::initPiece(Piece *piecePtr, int i, int j,Piece::Color color)
{
        piecePtr->setXY({i,j});
        piecePtr->setColor(color);
        Sprite sprite;
        if(color == Piece::Color::Black){
            sprite.setTexture(&m_textures->get(TextureId::checkers_black_piece));   
        }
        if(color == Piece::Color::White){
            sprite.setTexture(&m_textures->get(TextureId::checkers_white_piece));
        }
        sprite.setPosition(j*CELL_SIZE + BOARD_POS_X, i* CELL_SIZE + BOARD_POS_Y);
        piecePtr->setSprite(sprite);
}

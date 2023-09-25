#include "Game.hpp"


#include <fstream>
#include "CellSizeController.hpp"

#include <iostream>
#include <thread>

using namespace std::chrono_literals;

Game::Game(unsigned height, unsigned width, std::string title) 
{
   
    const auto cellRealSize = 110;  
    window.create(cellRealSize * 8,cellRealSize * 8, "MyChess");
    backGround.initSprites(0, loadingScreen.getTexture("board"));
}

// could use state pattern here
void Game::start(){
    loadingScreen.start(*controller,window,event);

    while(window.isOpen()){
        auto thereIsEvent = controller->queryEvents(window,event);
        std::this_thread::sleep_for(1ms);
        if(thereIsEvent || onceFlag){
            onceFlag = false;
            window.clear();
            backGround.draw(window);
            boardView->draw(window);
            window.display();
        }
    }
}

void Game::createBoard(std::unique_ptr<PieceAbstractFactory> pieceFactory, std::unique_ptr<AbstractSystemFactory> systemFactory){


    std::unique_ptr<AbstractBoardModel> boardModel= systemFactory->createBoardModel();
    boardView = systemFactory->createBoardView();
    controller = systemFactory->createController();

    createPieces(boardModel.get(), std::move(pieceFactory));

    controller->setModel(boardModel.get());
    boardView->setModel(std::move(boardModel));
}

void Game::createPieces(AbstractBoardModel* boardModel, std::unique_ptr<PieceAbstractFactory> pieceFactory){
    
    for(int i = 0; i < 16; ++i){
        
        auto pawn = pieceFactory->makePawn();
        initPiece(pawn.get(),1);
        boardModel->addPiece(std::move(pawn));
    }

    for(int i = 0; i < 4; ++i){
        auto bishop = pieceFactory->makeBishop();
        initPiece(bishop.get(),181);
        boardModel->addPiece(std::move(bishop));
    }
 
    for(int i = 0; i < 4; ++i){
        auto Rook = pieceFactory->makeRook();
        initPiece(Rook.get(),121);
        boardModel->addPiece(std::move(Rook));
    }
  
    for(int i = 0; i < 4; ++i){
        auto knight = pieceFactory->makeKnight();
        initPiece(knight.get(),61);
        boardModel->addPiece(std::move(knight));
    }
    for(int i = 0; i < 2; ++i){
        auto king = pieceFactory->makeKing();
        initPiece(king.get(),301);
        boardModel->addPiece(std::move(king));
    }
    
    for(int i = 0; i < 2; ++i){
        auto queen = pieceFactory->makeQueen();
        initPiece(queen.get(),241);
        boardModel->addPiece(std::move(queen));
    }
}

void Game::initPiece(Piece *piece, int rectXpos, int sizeX, int sizeY){
    const auto cellRealSize = 110;  
    auto& s = piece->getSprite();
    int distanceY = cellRealSize + 1;
    s.setTexture(&loadingScreen.getTexture("board")); 
    if(piece->getColor() == Piece::Color::Black){
        s.setStartingRect({rectXpos,1}, {sizeX, sizeY});
    }
    else{
        s.setStartingRect({rectXpos,1 + distanceY},{sizeX, sizeY});
    }
}

#include "Game.hpp"

Game::Game(std::unique_ptr<Window> window_)
    : window(std::move(window_))
{

}

void Game::start(){

    loadingScreen.start(*controller,*window,event);

    while(window->isOpen()){
        controller->queryEvents(*window, event);

        window->clear();

        backGround.draw();
        
        boardView->draw(*window, loadingScreen["board"]);

        window->display();
    }
}

void Game::createBoard(std::unique_ptr<PieceAbstractFactory> pieceFactory, std::unique_ptr<AbstractSystemFactory> systemFactory){


    std::unique_ptr<AbstractBoardModel> boardModel= systemFactory->createBoardModel();
    boardView = systemFactory->createBoardView();
    controller = systemFactory->createController();

    for(int i = 0; i < 16; ++i){
        boardModel->addPiece(pieceFactory->makePawn());
    }

    boardModel->addPiece(pieceFactory->makebishop());
    boardModel->addPiece(pieceFactory->makebishop());
    boardModel->addPiece(pieceFactory->makebishop());
    boardModel->addPiece(pieceFactory->makebishop());
    
    boardModel->addPiece(pieceFactory->makeKnight());
    boardModel->addPiece(pieceFactory->makeKnight());
    boardModel->addPiece(pieceFactory->makeKnight());
    boardModel->addPiece(pieceFactory->makeKnight());
    
    boardModel->addPiece(pieceFactory->makeQueen());
    boardModel->addPiece(pieceFactory->makeQueen());
    
    boardModel->addPiece(pieceFactory->makeKing());
    boardModel->addPiece(pieceFactory->makeKing());
    
    boardModel->addPiece(pieceFactory->makeRook());
    boardModel->addPiece(pieceFactory->makeRook());
    boardModel->addPiece(pieceFactory->makeRook());
    boardModel->addPiece(pieceFactory->makeRook());

    boardView->setModel(std::move(boardModel));
}

void Game::setWindow(std::unique_ptr<Window> window){
    this->window = std::move(window);
}

// void Game::setView(AbstractBoardView* boardView_){
//     this->boardView = boardView_;
// }

// void Game::setController(Controller *controller_){
//     this->controller = controller_;
// }

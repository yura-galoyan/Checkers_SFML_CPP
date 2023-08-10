#include "Game.hpp"

void Game::start()
{
    //Gameloop starts here...
    while(window.isOpen()){
        controller.queryEvents(event);


        window.clear();

        backGround.draw();
        boardView->draw(window);

        window.display();
    }
}

std::unique_ptr<AbstractBoardModel> Game::createBoard(std::unique_ptr<ChessAbstractFactory> factory)
{

    std::unique_ptr<AbstractBoardModel> board = factory->makeBoard();

    for(int i = 0; i < 16; ++i){
        board->addPiece(factory->makePawn());
    }

    board->addPiece(factory->makebishop());
    board->addPiece(factory->makebishop());
    board->addPiece(factory->makebishop());
    board->addPiece(factory->makebishop());
    board->addPiece(factory->makeKnight());
    board->addPiece(factory->makeKnight());
    board->addPiece(factory->makeKnight());
    board->addPiece(factory->makeKnight());
    board->addPiece(factory->makeQueen());
    board->addPiece(factory->makeQueen());
    board->addPiece(factory->makeKing());
    board->addPiece(factory->makeKing());
    board->addPiece(factory->makeRook());
    board->addPiece(factory->makeRook());
    board->addPiece(factory->makeRook());
    board->addPiece(factory->makeRook());

    return board;
}

void Game::setView(AbstractBoardView* boardView_)
{
    this->boardView = boardView_;
}


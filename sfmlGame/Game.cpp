#include "Game.hpp"

void Game::start()
{
    //Gameloop starts here...


    event.handleEvents();
    //Gameloop ends here...
}

void Game::handleEvents()
{
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
    this->boardView = boardView;
}


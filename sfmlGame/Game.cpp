#include "Game.hpp"

#include <iostream>

void Game::start()
{
    //Gameloop starts here...
    while(window.isOpen()){
        controller->queryEvents(window,event);


        window.clear();

        backGround.draw();
        boardView->draw(window);

        window.display();
    }
}

std::unique_ptr<AbstractBoardModel> Game::createBoard(std::unique_ptr<ChessAbstractFactory> factory)
{

    std::unique_ptr<AbstractBoardModel> board = factory->makeBoard();

    // for(int i = 0; i < 16; ++i){
        // board->addPiece(factory->makePawn());
    // }

    
    board->addPiece(factory->makebishop());
    board->addPiece(factory->makebishop());
    board->addPiece(factory->makebishop());
    board->addPiece(factory->makebishop());

    std::cout << std::string(100,'-') << std::endl;
    std::cout << std::string(100,'-') << std::endl;
   
    for(auto& p: *board){
        std::cout << "x: " << p->getXY().first << "\n";
        std::cout << "y: " << p->getXY().second << "\n";
        std::cout << std::string(100,'-') << std::endl;
    }


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

void Game::setView(AbstractBoardView* boardView_){
    this->boardView = boardView_;
}

void Game::setController(Controller *controller_){
    this->controller = controller_;
}

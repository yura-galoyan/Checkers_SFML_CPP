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

    auto b1 = factory->makebishop();
    std::cout<< "x:" << b1->getXY().first << "\n";
    std::cout<< "y:" << b1->getXY().second << "\n";

    auto b2 = factory->makebishop();
    std::cout<< "x:" << b2->getXY().first << "\n";
    std::cout<< "y:" << b2->getXY().second << "\n";

    auto b3 = factory->makebishop();
    std::cout<< "x:" << b3->getXY().first << "\n";
    std::cout<< "y:" << b3->getXY().second << "\n";

    auto b4 = factory->makebishop();
    std::cout<< "x:" << b4->getXY().first << "\n";
    std::cout<< "y:" << b4->getXY().second << std::endl;
    
    board->addPiece(std::move(b1));
    board->addPiece(std::move(b2));
    board->addPiece(std::move(b3));
    board->addPiece(std::move(b4));

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

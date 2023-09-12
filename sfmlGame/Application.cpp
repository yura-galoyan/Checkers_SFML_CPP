#include "Application.hpp"

#include "Factories/PiecePrototypeFactory.hpp"
#include "Factories/SfmlSystemFactory.hpp"

Application::Application(){

    std::unique_ptr<PiecePrototypeFactory> pieceFactory = std::make_unique<PiecePrototypeFactory>(
        std::make_unique<Pawn>(),std::make_unique<Queen>(), std::make_unique<Rook>(),
        std::make_unique<Knight>(), std::make_unique<Bishop>(),std::make_unique<King>()
    );

    std::unique_ptr<SfmlSystemFactory> systemFactory = std::make_unique<SfmlSystemFactory>();

    Game game;
    game.createBoard(std::move(pieceFactory), std::move(systemFactory));

    

    

}

void Application::execute(){
    
}
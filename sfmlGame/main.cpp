#include "Factories/PiecePrototypeFactory.hpp"
#include "Factories/SfmlSystemFactory.hpp"
#include "RegularBoardModel.hpp"
#include "RegularBoardView.hpp"
#include "Game.hpp"

#include <iostream>

int main(){

    Game game(900, 900, "Chess Game");

    std::unique_ptr<PiecePrototypeFactory> pieceFactory = std::make_unique<PiecePrototypeFactory>(
        std::make_unique<Pawn>(),std::make_unique<Queen>(), std::make_unique<Rook>(),
        std::make_unique<Knight>(), std::make_unique<Bishop>(),std::make_unique<King>()
    );

    std::unique_ptr<SfmlSystemFactory> systemFactory = std::make_unique<SfmlSystemFactory>();

    std::unique_ptr<AbstractBoardView> view = std::make_unique<RegularBoardView>();
    std::unique_ptr<Controller> controller = std::make_unique<SfmlController>();

    game.createBoard(std::move(pieceFactory), std::move(systemFactory));


    game.start();

}
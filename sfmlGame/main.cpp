#include "Factories/ChessPrototypeFactory.hpp"
#include "RegularBoardModel.hpp"
#include "RegularBoardView.hpp"
#include "SfmlController.hpp"
#include "Game.hpp"


int main(){

    Game game;

    
    auto model = game.createBoard( std::make_unique<ChessPrototypeFactory>( 
        std::make_unique<Pawn>(),std::make_unique<Queen>(), std::make_unique<Rook>(),
        std::make_unique<Knight>(), std::make_unique<Bishop>(),std::make_unique<King>(),
        std::make_unique<RegularBoardModel>() ));

// Make this Factory
    std::unique_ptr<AbstractBoardView> view = std::make_unique<RegularBoardView>();
    std::unique_ptr<Controller> controller = std::make_unique<SfmlController>();


    view->setModel(model.get());


    game.setView(view.get());


}
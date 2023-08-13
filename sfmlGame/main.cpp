#include "Factories/ChessPrototypeFactory.hpp"
#include "RegularBoardModel.hpp"
#include "RegularBoardView.hpp"
#include "SfmlController.hpp"
#include "Game.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <thread>


// sf::Texture loadTexture(){
//     sf::Texture texture;
//     if(!texture.loadFromFile("assets/chessBoard.png")){
//         std::cout << "failed to load chessBoard.png" << std::endl;
//     }


//     std::cout << " texture laoded" << std::endl;
//     return texture;    

// }

int main(){

    Game game(900, 1600, "Chess Game");

    
// Change this somehow
    auto model = game.createBoard( std::make_unique<ChessPrototypeFactory>( 
        std::make_unique<Pawn>(),std::make_unique<Queen>(), std::make_unique<Rook>(),
        std::make_unique<Knight>(), std::make_unique<Bishop>(),std::make_unique<King>(),
        std::make_unique<RegularBoardModel>() ));

// Make this Factory
    std::unique_ptr<AbstractBoardView> view = std::make_unique<RegularBoardView>();
    std::unique_ptr<Controller> controller = std::make_unique<SfmlController>();


    view->setModel(model.get());

    game.setView(view.get());
    game.setController(controller.get());



}
#include "TextureManager.hpp"

void TextureManager::initPieces(){
    Texture tex;
    textures["pieces"] = tex;   
    textures["pieces"].loadFromFile("../assets/chessBoard.png");
}

void TextureManager::initMenu(){
    
}

void TextureManager::initLoadingScreen(){
    Texture tex;
    textures["loading_screen"] = tex;   
    textures["loading_screen"].loadFromFile("../assets/loadingScreen.png");
}

void TextureManager::initGame(){
    initPieces();
    initMenu();
}

Texture &TextureManager::operator[](std::string key){
    return textures[key];
}

#include "TextureManager.hpp"

void TextureManager::initPieces(){
    Texture tex;
    textures["board"] = tex;   
    textures["board"].loadFromFile("../assets/board58x110.png");
}

void TextureManager::initMenu(){
    
}

void TextureManager::initLoadingScreen(){
    Texture tex;
    textures["loading_screen"] = tex;   
    textures["loading_screen"].loadFromFile("../assets/loading.png");
}

void TextureManager::initGame(){
    initPieces();
    initMenu();
}

Texture& TextureManager::operator[](std::string key){
    return textures[key];
}

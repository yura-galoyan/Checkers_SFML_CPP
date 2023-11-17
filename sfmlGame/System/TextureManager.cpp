#include "TextureManager.hpp"
/*

// void TextureManager::initPieces(){
//    // Texture tex;
//    // textures["board"] = tex;   
//    // textures["board"].loadFromFile("../assets/board58x110.png");
// }

// void TextureManager::initMenu(){

// }

// void TextureManager::initLoadingScreen()
// {
//    // Texture tex;
//    // textures["loading_screen"] = tex;   
//    // textures["loading_screen"].loadFromFile("../assets/loading.png");
// }
// void TextureManager::initGame(){
//     // initPieces();
//     // initMenu();
// }

*/

void TextureManager::addTexture(std::string name, std::string path)
{
    Texture tex;
    textures[name] = tex;
    textures[name].loadFromFile(path);
}
Texture& TextureManager::operator[](std::string key){
    return textures[key];
}

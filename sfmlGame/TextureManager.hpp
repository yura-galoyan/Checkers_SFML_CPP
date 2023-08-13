#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP
#endif //TEXTURE_MANAGER_HPP

#include "Texture.hpp"

#include <unordered_map>

class TextureManager
{
public:
    void initLoadingScreen();    
    void initGame();
    Texture& operator[](std::string key);

private:
    void initPieces();
    void initMenu();



private:
    std::unordered_map<std::string, Texture> textures;
    Texture pieces;
    Texture loadingScreen;
};

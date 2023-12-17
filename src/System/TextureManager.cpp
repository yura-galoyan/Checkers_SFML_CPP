#include "TextureManager.hpp"

void TextureManager::addTexture(std::string name, std::string path)
{
    Texture tex;
    textures[name] = tex;
    textures[name].loadFromFile(path);
}
Texture& TextureManager::operator[](std::string key){
    return textures[key];
}

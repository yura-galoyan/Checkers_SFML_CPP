#include "Texture.hpp"

bool Texture::loadFromFile(std::string path){
    return tex.loadFromFile(path);
}

sf::Texture& Texture::getTexture(){
    return tex;
}
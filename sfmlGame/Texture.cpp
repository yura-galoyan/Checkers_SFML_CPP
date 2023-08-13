#include "Texture.hpp"

void Texture::loadFromFile(std::string path){
    tex.loadFromFile(path);
}

sf::Texture& Texture::getTexture(){
    return tex;
}
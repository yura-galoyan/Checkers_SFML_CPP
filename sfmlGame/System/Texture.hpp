#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <SFML/Graphics/Texture.hpp>

#include <string>

class Texture
{
public:
    bool loadFromFile(std::string path){
        return tex.loadFromFile(path);
    }

    sf::Texture& getTexture(){
        return tex;
    }

private:
    sf::Texture tex;
};

#endif //TEXTURE_HPP
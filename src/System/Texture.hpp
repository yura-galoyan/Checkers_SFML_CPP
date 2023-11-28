#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <SFML/Graphics/Texture.hpp>

#include <string>
#include <stdexcept>


class Texture
{
public:
    bool loadFromFile(std::string path){
        if (!tex.loadFromFile(path)) {
            throw std::runtime_error{ "can not open file" };
        };
    }

    sf::Texture& getTexture(){
        return tex;
    }

private:
    sf::Texture tex;
};

#endif //TEXTURE_HPP
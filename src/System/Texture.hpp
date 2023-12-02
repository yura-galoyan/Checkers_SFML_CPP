#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <SFML/Graphics/Texture.hpp>

#include <string>
#include <stdexcept>

class Texture
{
public:
#ifdef __GNUC__
    bool loadFromFile(std::string path){
        if(!tex.loadFromFile(path)){
            throw std::runtime_error{""};
        }
        return true;
    }
#elif defined(_MSC_VER)
    bool loadFromFile(std::string path){
            return tex.loadFromFile(path);
        }
#endif
    sf::Texture& getTexture(){
        return tex;
    }


private:
    sf::Texture tex;
};

#endif //TEXTURE_HPP
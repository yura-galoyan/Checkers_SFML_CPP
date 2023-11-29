#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <SFML/Graphics/Texture.hpp>

#include <string>
#include <stdexcept>

#define GCC_COMPILER (defined(__GNUC__) && !defined(__clang__))


class Texture
{
public:
#ifdef GCC_COMPILER
    bool loadFromFile(std::string path){
            return tex.loadFromFile(path);
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
#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <SFML/Graphics/Texture.hpp>

#include <string>

class Texture
{
public:
    void loadFromFile(std::string path);

    sf::Texture& getTexture();

private:
    sf::Texture tex;
};

#endif //TEXTURE_HPP
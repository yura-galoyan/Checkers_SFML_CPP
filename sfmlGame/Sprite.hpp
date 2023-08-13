#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <utility>

#include <SFML/Graphics/Sprite.hpp>

#include "Texture.hpp"
#include "Window.hpp"

class Sprite
{
    using Vector2 = std::pair<unsigned,unsigned>;

public:   
    Sprite(Texture* texture, sf::Vector2i position, sf::Vector2i size);
    void setTexture(Texture* texture);
    void draw(Window& window);
    void setRect(sf::Vector2i pos, sf::Vector2i size);

private:
    sf::Vector2i position;
    sf::Vector2i size;
    sf::Sprite sprite;
    Texture* texture;
};


#endif //SPRITE_HPP
#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <utility>

#include <SFML/Graphics/Sprite.hpp>

#include "Texture.hpp"
#include "Window.hpp"

class Sprite
{
public:
    using Vector2i = sf::Vector2i;
    using Vector2f = sf::Vector2f;

public:
    Sprite() = default;
    Sprite(Vector2i position, Vector2i size);
    Sprite(const Sprite& sprite) = default;
    Sprite& operator=(const Sprite&) = default;
    
    void setTexture(Texture* texture);
    void draw(Window& window);
    void setRect(Vector2i pos, Vector2i size);
    void setRectPosY(int y);
    void setPosition(float x, float y);

    Vector2f getPosition() const { return sprite.getPosition(); }
    Vector2i getRectPos() const { return position; };

private:
    Vector2i position;
    Vector2i size;
    Texture* texture;

private:
    sf::Sprite sprite;
};


#endif //SPRITE_HPP
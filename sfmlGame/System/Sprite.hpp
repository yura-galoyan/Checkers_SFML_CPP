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
    Sprite(Vector2i rectPosition, Vector2i size);
    Sprite(const Sprite& sprite) = default;
    Sprite& operator=(const Sprite&) = default;
    
    void setTexture(Texture* texture);
    void draw(Window& window);
    void setStartingRect(Vector2i pos, Vector2i size);
    void setCurrRectPosY(int y);
    void setCurrRectPosX(int x);
    void setPosition(float x, float y);
    void setDistanceX(unsigned x);

    auto getPosition() { return sprite.getPosition(); }

    unsigned getDistanceX() const { return distanceX; }
    Vector2i getSize() const { return size; }
    Vector2f getPosition() const { return sprite.getPosition(); }
    Vector2i getCurrRectPos() const { return currRectPosition; };
    Vector2i getStartingRectPos() const { return startingRectPos; }


private:
    Vector2i size;
    Texture* texture;

private:
    Vector2i startingRectPos;
    Vector2i currRectPosition;
    unsigned distanceX;

private:
    sf::Sprite sprite;
};


#endif //SPRITE_HPP


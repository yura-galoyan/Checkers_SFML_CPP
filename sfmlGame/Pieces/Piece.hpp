#ifndef PIECE_HPP
#define PIECE_HPP

#include <memory>

#include "../System/Sprite.hpp"
#include "../System/Window.hpp"

class Piece
{
public:
    using Coords = std::pair<std::size_t, std::size_t>;
    enum class Color{ White, Black};

public:
    Piece() = default;
    virtual ~Piece() = default;

    virtual std::unique_ptr<Piece> clone() const = 0;

public:
    void setPosition(std::size_t x);

    void setXY(Coords xy_){ xy = xy_; }
    Coords getXY() const { return xy; }

    void setSprite(const Sprite& sprite);

    void setColor(Color c_){ color = c_; }
    Color getColor() const { return color; }

    virtual void moveTo(Coords xy) = 0;
    virtual void draw(Window& window, Texture& texture) = 0;

protected:
    Coords xy;
    Color color;
    Sprite sprite;
    
    

};


#endif //PIECE_HPP
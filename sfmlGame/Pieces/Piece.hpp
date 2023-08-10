#ifndef PIECE_HPP
#define PIECE_HPP

#include <memory>

#include "../Window.hpp"

class Piece
{
public:
    using Coords = std::pair<std::size_t, std::size_t>;
    enum class Color{ White, Black};

public:
    virtual std::unique_ptr<Piece> clone() const = 0;
    virtual ~Piece() = default;

    void setPosition(std::size_t x);

    void setXY(Coords xy_){ xy = xy_; }
    Coords getXY() const { return xy; }

    void setColor(Color c_){ color = c_; }
    Color getColor() const { return color; }

    virtual void move(Coords xy) = 0;
    virtual void draw(Window& window) = 0;

protected:
    Coords xy;
    Color color;


};


#endif //PIECE_HPP
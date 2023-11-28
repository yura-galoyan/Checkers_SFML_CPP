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
    Sprite& getSprite() { return sprite; }
    void setColor(Color c_){ color = c_; }
    Color getColor() const { return color; }

    void moveTo(Coords xy);
    virtual bool isValid(Coords from, Coords to) const = 0;
    virtual void draw(Window& window) = 0;

protected:
    Coords xy;
    Color color;
    Sprite sprite;
    int offsetX{20};
    int offsetY{0};

protected:
    bool isStarted() { return startedDrawing; }
    void setStarted(bool state) { startedDrawing = state; }

private:
    bool startedDrawing{false};
    

};


#endif //PIECE_HPP
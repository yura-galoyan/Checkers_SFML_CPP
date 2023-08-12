#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics/RenderWindow.hpp>

#include <string>

#include "Event.hpp"

class Window
{
public:
    Window() = default;
    Window(unsigned height, unsigned width, std::string title);
    void draw(const sf::Drawable& drawable);
    bool pollEvent(Event& event);
    bool isOpen();
    void close();
    void clear();
    void display();
    void create(unsigned height, unsigned width, std::string title);

    int gerWidth() { return width; }
    int gerheight() { return height; }


private:
    sf::RenderWindow window;
    int width;
    int height;
};

#endif //WINDOW_HPP


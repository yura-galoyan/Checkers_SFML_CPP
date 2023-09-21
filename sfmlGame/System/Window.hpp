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
    void setView(const sf::View& view);
    void setSize(std::pair<unsigned int,unsigned int>);
    std::pair<unsigned int,unsigned int> getSize() { return {window.getSize().x,window.getSize().y}; }

    int getStartWidth() { return width; }
    int gerStartheight() { return height; }

    operator sf::RenderWindow&() { return window;}

private:
    sf::RenderWindow window;
    unsigned width;
    unsigned height;
};

#endif //WINDOW_HPP


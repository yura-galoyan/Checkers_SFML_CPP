#ifndef MOUSE_HPP
#define MOUSE_HPP

#include <SFML/Window/Mouse.hpp>

#include "Window.hpp"

struct Mouse
{
    static auto getPosition(Window& window){
        return sf::Mouse::getPosition(window);
    }
};


#endif //MOUSE_HPP
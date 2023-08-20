#ifndef MOUSE_HPP
#define MOUSE_HPP

#include <SFML/Window/Mouse.hpp>

struct Mouse
{
    static auto getPosition(){
        return sf::Mouse::getPosition();
    }
};


#endif //MOUSE_HPP
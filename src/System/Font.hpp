#ifndef FONT_HPP
#define FONT_HPP

#include <SFML/Graphics/Font.hpp>

#include <string>
#include <stdexcept>

class Font
{
public:
    bool loadFromFile(std::string path){

        if (!font.loadFromFile(path))
        {
            throw std::runtime_error{ "can not open file" };
        };
    }
    sf::Font& getFont(){ return font; }

private:
    sf::Font font;
};


#endif //FONT_HPP
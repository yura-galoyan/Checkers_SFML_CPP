#ifndef FONT_HPP
#define FONT_HPP

#include <SFML/Graphics/Font.hpp>

#include <string>

class Font
{
public:
    bool loadFromFile(std::string path){
        return font.loadFromFile(path);
    }
    sf::Font& getFont(){ return font; }

private:
    sf::Font font;
};


#endif //FONT_HPP
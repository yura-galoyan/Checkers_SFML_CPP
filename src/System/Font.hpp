#ifndef FONT_HPP
#define FONT_HPP

#include <SFML/Graphics/Font.hpp>

#include <string>
#include <stdexcept>

/// TODO: maybe turn this into template "Resource<typename ResourceType>"

class Font
{
public:

#ifdef __GNUC__
    bool loadFromFile(std::string path){
        return font.loadFromFile(path);

    }
#elif defined(_MSC_VER)
    bool loadFromFile(std::string path){
            return font.loadFromFile(path);
        }
#endif

    sf::Font& getFont(){ return font; }

private:
    sf::Font font;
};


#endif //FONT_HPP
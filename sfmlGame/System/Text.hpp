#ifndef SYSTEM_TEXT_HPP
#define SYSTEM_TEXT_HPP

#include <SFML/Graphics/Text.hpp>

#include "Font.hpp"
#include "Window.hpp"



#include <string>

class Text
{
public:
    Text() = default;
    Text(const std::string& content);
    void draw(Window& window);
    void setFont(Font* font);
    void setText(const std::string& content);
    void setPosition(sf::Vector2f pos) { m_data.setPosition(pos); };
    void setCharacterSize(unsigned int size_) { m_data.setCharacterSize(size_); };

    auto getPosition() const { return m_data.getPosition(); }
    auto getCharacterSize() const { return m_data.getCharacterSize(); }



private:
    sf::Text m_data;
    Font* m_font;

};

#endif //SYSTEM_TEXT_HPP

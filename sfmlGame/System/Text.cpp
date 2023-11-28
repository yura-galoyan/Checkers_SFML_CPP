#include "Text.hpp"

Text::Text(){
    m_data.setOutlineColor(sf::Color::Black);
    m_data.setFillColor(sf::Color::White);
}

Text::Text(const std::string& context){
    m_data.setString(context);
    m_data.setOutlineColor(sf::Color::Black);
    m_data.setFillColor(sf::Color::White);

}

void Text::draw(Window &window)
{
    window.draw(m_data);
}

void Text::setFont(Font *font)
{
    m_font = font;
    if(m_font){
        m_data.setFont(m_font->getFont());
    }
}

void Text::setText(const std::string &content, std::string color)
{
    if(color == "white"){
        m_data.setColor(sf::Color::White);
    }
    if(color == "green"){
        m_data.setColor(sf::Color::Green);
    }
        m_data.setString(content);
}



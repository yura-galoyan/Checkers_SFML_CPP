#include <SFML/Graphics.hpp>
#include "controller.hpp"
#ifndef STATS_HPP
#define STATS_HPP

class Stats
{
public:
    Stats(sf::RenderWindow& window, std::string name ):window(window){
        initFont(name);
        text.setFont(font);
        text.setOutlineColor(sf::Color::Red);
    };
    ~Stats( );
    void showStatsOf( std::string name, Controller::KeyboardEvents::KeyStates keyStates);

    void showAllStats(Controller::KeyboardEvents keyEvents);

private:
    void initFont(std::string name);

private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text text;    

};

#endif //STATS_HPP
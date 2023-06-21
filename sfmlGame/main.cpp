#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <vector>
#include "controller.hpp"
#include "stats.hpp"

sf::Vector2<float> start{};
sf::Vector2<float> end{};
using Line  = std::array<sf::Vertex,2>;
using LinesVec = std::vector<Line>;


void calculateDistance(Controller::KeyboardEvents keyEvents, bool&, sf::RenderWindow&, LinesVec&);
int main(){
    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");
    window.setKeyRepeatEnabled(false);
    sf::CircleShape shape(100.f);
    sf::Event event;
    Controller controller;
    bool enabl{};
    bool keepDrawing{};
    controller.initKeys();
    Stats stats(window,"Mythical_Prince.ttf");

    LinesVec lines;

    while (window.isOpen()){
        controller.handleEvents(event,window);
        calculateDistance(controller.getKeyEvents(),enabl,window, lines);

        window.clear();
        
        if(enabl){
            keepDrawing = true;
        }

        if(enabl || keepDrawing){
            for(auto line :lines){
                window.draw(line.data(),2,sf::Lines);
            }
            enabl = false;
        }
        stats.showAllStats(controller.getKeyEvents());
        window.display();

    }

    return 0;
}

void calculateDistance(Controller::KeyboardEvents keyEvents, bool& enabled, sf::RenderWindow& window, LinesVec& vec){
    static Line line;

    if(keyEvents.mouseLeft.pressed){
        start.x = sf::Mouse::getPosition(window).x;
        start.y = sf::Mouse::getPosition(window).y;
        line[0] = start;
    }
    if(keyEvents.mouseLeft.released){
        end.x = sf::Mouse::getPosition(window).x;
        end.y = sf::Mouse::getPosition(window).y;
        line[1] = end;
        enabled = true;
        vec.push_back(line);
    }
    if(keyEvents.mouseRight.pressed){
        if(!vec.empty()){
            vec.pop_back();
        }
    }

};
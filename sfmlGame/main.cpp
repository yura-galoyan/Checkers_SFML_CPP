#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <vector>
#include "controller.hpp"
#include "stats.hpp"

using Dot = sf::RectangleShape;
using DotVector = std::vector<Dot>;

using Line  = std::array<sf::Vertex,2>;
using LinesVec = std::vector<Line>;

Dot start{};
Dot end{};

bool operator!=(Dot l, Dot r){
    bool ret = l.getPosition().x == r.getPosition().x &&
    l.getPosition().y == r.getPosition().y;
    return !ret;
}

void calculateDistance(Controller::KeyboardEvents keyEvents, bool&, sf::RenderWindow&, DotVector&);
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

    DotVector dotes;
    start.setSize(sf::Vector2<float>{15.0f, 15.0f});
    start.setFillColor(sf::Color::Red);
    while (window.isOpen()){
        controller.handleEvents(event,window);
        calculateDistance(controller.getKeyEvents(),enabl,window, dotes);

        window.clear();
        for(auto dot : dotes){
            window.draw(dot);
        }
        stats.showAllStats(controller.getKeyEvents());
        window.display();
    }

    return 0;
}

void calculateDistance(Controller::KeyboardEvents keyEvents, bool& enabled, sf::RenderWindow& window, DotVector& vec){


    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        start.setPosition(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y);
        if(!vec.empty()){
            if(vec.back() != start){
                vec.push_back(start);
            }
        }
        else{
            vec.push_back(start);
        }
    }

    if(keyEvents.mouseRight.pressed){
        if(!vec.empty()){
            vec.pop_back();
        }
    }

};
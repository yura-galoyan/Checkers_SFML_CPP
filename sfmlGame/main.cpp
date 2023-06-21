#include <SFML/Graphics.hpp>
#include <iostream>
#include "controller.hpp"
#include "stats.hpp"

sf::Vector2<float> start{};
sf::Vector2<float> end{};

sf::Vertex lineCached[2];
sf::Vertex line[2];


void drawLine(bool enabled);
void calculateDistance(Controller::KeyboardEvents keyEvents, bool&, sf::RenderWindow&);
float distance;
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
    while (window.isOpen()){
        controller.handleEvents(event,window);
        calculateDistance(controller.getKeyEvents(),enabl,window);

        window.clear();

        if(distance){
            std::cout<<"distance = "<<distance<<std::endl;
        }
        
        if(enabl){
            keepDrawing = true;
            lineCached[0] = line[0];
            lineCached[1] = line[1];
        }

        if(enabl || keepDrawing){
            window.draw(lineCached,2,sf::Lines);
            enabl = false;
        }
        stats.showAllStats(controller.getKeyEvents());
        window.display();


        distance = 0;
    }
    return 0;
}
void drawLine(bool enabled){
    if(enabled){
        line[0] = start;
        enabled = false;
    }
}

void calculateDistance(Controller::KeyboardEvents keyEvents, bool& enabled, sf::RenderWindow& window){

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
    } 
};
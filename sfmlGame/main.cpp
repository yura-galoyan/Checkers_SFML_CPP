#include <SFML/Graphics.hpp>
#include "controller.hpp"
void test(sf::RenderWindow& window);

void handleEvents(sf::Event& event, sf::RenderWindow& window);

int main(){
    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);


    sf::Event event;
    Controller controller;
    controller.initKeys();
    while (window.isOpen())
    {
        controller.handleEvents(event,window);
        window.clear();

        test(window);

        window.draw(shape);
        window.display();
    }

    return 0;
}


void handleEvents(sf::Event& event, sf::RenderWindow& window) {
};

void test(sf::RenderWindow& window) {
    
};

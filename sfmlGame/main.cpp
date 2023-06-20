#include <SFML/Graphics.hpp>
#include <iostream>
#include "controller.hpp"
void test(sf::RenderWindow& window);

void handleEvents(sf::Event& event, sf::RenderWindow& window);

int main(){
    std::string fontPath = "../Font/";
    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");
    sf::CircleShape shape(100.f);
    sf::Font font; 
    if (!font.loadFromFile(fontPath + "Mythical_Prince.ttf")) {
        if (!font.loadFromFile("../" + fontPath + "Mythical_Prince.ttf")) {
            std::cout << "could not load mythical prince font file" << std::endl;
        }
    }
    sf::Text text("hello",font);
    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color::Red);
    shape.setFillColor(sf::Color::Green);


    sf::Event event;
    Controller controller;
    controller.initKeys();
    while (window.isOpen())
    {
        controller.handleEvents(event,window);
        window.clear();

        test(window);
        window.draw(text);
        window.display();
    }

    return 0;
}


void handleEvents(sf::Event& event, sf::RenderWindow& window) {
};

void test(sf::RenderWindow& window) {
    
};

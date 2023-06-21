#include "stats.hpp"


#include <iostream>

Stats::~Stats( ){

}

void Stats::initFont(std::string name){
    std::string fontPath = "../Font/";
    if (!font.loadFromFile(fontPath + name)) {
        if (!font.loadFromFile("../" + fontPath + name)) { }
    }
};


void Stats::showStatsOf(std::string name, Controller::KeyboardEvents::KeyStates keyStates){
    if(keyStates.pressed){
        std::cout<<name<<" button pressed"<<std::endl;
    }
    if(keyStates.released){
        std::cout<<name<<" button released"<<std::endl;
    }
    if(keyStates.onHold){
        text.setString(name + " button hold");
        window.draw(text);
        text.move(sf::Vector2<float>{0.f,30.0f});
    }
};


void Stats::showAllStats(Controller::KeyboardEvents keyEvents){

    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color::Red);

    showStatsOf("mouse Left",keyEvents.mouseLeft);
    showStatsOf("mouse right",keyEvents.mouseRight);
    showStatsOf("w key",keyEvents.w_key);

    text.setPosition(sf::Vector2<float>{});

}
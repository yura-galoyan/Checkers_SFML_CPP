#ifndef EVENT_HPP
#define EVENT_HPP

#include <SFML/Window/Event.hpp>

class Event
{
public:
    void handleEvents();
    //event variable getEvent();
private:
    sf::Event currEvent;
};


#endif //EVENT_HPP


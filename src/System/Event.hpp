#ifndef EVENT_HPP
#define EVENT_HPP

#include <SFML/Window/Event.hpp>

class Event
{
public:
    sf::Event& event() { return currEvent; }
private:
    sf::Event currEvent;
};


#endif //EVENT_HPP


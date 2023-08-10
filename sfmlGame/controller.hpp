#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP


#include <unordered_map>
#include <string>

#include "Event.hpp"

class Controller
{
public:
    struct Key{
        bool notTouched{false};
        bool pressedOnce{false};
        bool onHold{false};
        bool released{true};    
    };
    void queryEvents(Event& event);

private:
    std::unordered_map<char, Key> keyboard;
    std::unordered_map<std::string, Key> mouse;
};


#endif //CONTROLLER_HPP
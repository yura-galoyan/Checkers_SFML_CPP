#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <unordered_map>
#include <string>

class Controller
{
public:
    struct Key{
        bool notTouched{false};
        bool pressedOnce{false};
        bool onHold{false};
        bool released{true};    
    };

    std::unordered_map<char, Key> keyboard;
    std::unordered_map<std::string, Key> mouse;
};


#endif //CONTROLLER_HPP
#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP


#include <unordered_map>
#include <string>

#include "Window.hpp"

class Controller
{
private:
    struct Key{
        Key() = default;
        bool notTouched{false};
        bool pressedOnce{false};
        bool onHold{false};
        bool released{true};    
    };

public:
    template<typename MouseButton>
    struct ButtonPair{
        MouseButton button;
        Key state;
    };

public:
    virtual void queryEvents(Window& window, Event& event) = 0;

protected:
    virtual void initMouseButtons() = 0;

};


#endif //CONTROLLER_HPP

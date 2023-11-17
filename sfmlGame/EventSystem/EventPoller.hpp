#ifndef EVENT_POLLER_HPP
#define EVENT_POLLER_HPP


#include "../System/Clock.hpp"
#include "../System/Window.hpp"
#include "../System/Event.hpp"


#include <unordered_map>


class EventPoller
{
public:
    EventPoller();

private:
    struct Key{
        Key() = default;
        bool doubleClicked{false};
        bool notTouched{true};
        bool clicked{false};
        bool onHold{false};
        bool shortReleased{true};    
        bool longReleased{true};    
    };

public:
    template<typename MouseButton>
    struct ButtonPair{
        MouseButton button;
        Key state;
    };

public:
    void setFlags(Window& window);

private:
    void initMouseButtons();
    void checkMouseButtonPressed(ButtonPair<char>& buttonPair, Event& event);
    void checkMouseButtonReleased(ButtonPair<char>& buttonPair, Event& event);
    void clearEvents();
    ButtonPair<char> atMouseButton(char button);
    auto& mouseButtons() { return m_mouseButtons;  }

private:
    std::unordered_map<char, ButtonPair<char> > m_mouseButtons;
    float longReleasedTime;
    Clock<float> clockReleased;
};


#endif //EVENT_POLLER_HPP
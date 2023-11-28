#ifndef EVENT_POLLER_HPP
#define EVENT_POLLER_HPP


#include "../System/Clock.hpp"
#include "../System/Window.hpp"
#include "../System/Event.hpp"



#include <unordered_map>

class iController;

class EventPoller
{
public:
    EventPoller();

private:

    template<typename KeyType, typename KeyStateType>
    struct InputControl{
        InputControl(KeyType data_, KeyStateType state_ = KeyStateType{}){
            data = data_;
            state = state_;
        }
        InputControl() = default;
        KeyType data;
        KeyStateType state;
    };

    enum MouseInput{
        Left = sf::Mouse::Button::Left,
        Right = sf::Mouse::Button::Right
    };
    


    struct MouseButtonState{
        MouseButtonState() = default;
        bool doubleClicked{false};
        bool notTouched{true};
        bool clicked{false};
        bool onHold{false};
        bool shortReleased{true};    
        bool longReleased{true};    
    };

    using MouseButton = InputControl<MouseInput, MouseButtonState>;

public:
    void setFlags(Window& window);
    void setController(iController* controller) { m_controller = controller; };

private:
    void initMouseButtons();
    void checkMouseButtonPressed(MouseButton& button, Event& event);
    void checkMouseButtonReleased(MouseButton& button, Event& event);

    void clearEvents();
    void mouseButtonClick(MouseInput button);

public:
    auto& mouseButtons() { return m_mouseButtons;  }

private:
    std::unordered_map<MouseInput, MouseButton > m_mouseButtons;
    iController* m_controller;
    float longReleasedTime;
    Clock<float> clockReleased;
};


#endif //EVENT_POLLER_HPP
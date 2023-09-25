#ifndef SFML_CONTROLLER_HPP
#define SFML_CONTROLLER_HPP

#include "Controller.hpp"

#include "Clock.hpp"

class SfmlController : public Controller
{
public:
    SfmlController();
    
private:
    bool setFlags(Window& window, Event& event) override;
    void initMouseButtons() override;
    void checkMouseButtonPressed(ButtonPair<char>& buttonPair, Event& event);
    void checkMouseButtonReleased(ButtonPair<char>& buttonPair, Event& event);
    void clearEvents();
    ButtonPair<char> atMouseButton(char button);

private:
    float longReleasedTime;
    Clock<float> clockReleased;
};


#endif //SFML_CONTROLLER_HPP
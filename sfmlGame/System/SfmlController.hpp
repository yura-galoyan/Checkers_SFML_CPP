#ifndef SFML_CONTROLLER_HPP
#define SFML_CONTROLLER_HPP

#include "Controller.hpp"

class SfmlController : public Controller
{
public:
    SfmlController();
    
private:
    void setFlags(Window& window, Event& event) override;
    void initMouseButtons() override;
    void checkMouseButtonPressed(ButtonPair<char>& buttonPair, Event& event);
    void checkMouseButtonReleased(ButtonPair<char>& buttonPair, Event& event);
    void clearEvents();
    ButtonPair<char> atMouseButton(char button);
private:
    // std::unordered_map<char, Key> keyboard;
    // std::unordered_map<char, ButtonPair<sf::Mouse::Button> > mouseButtons;
};


#endif //SFML_CONTROLLER_HPP
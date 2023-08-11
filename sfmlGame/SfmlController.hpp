#ifndef SFML_CONTROLLER_HPP
#define SFML_CONTROLLER_HPP

#include "Controller.hpp"

class SfmlController : public Controller
{
public:
    virtual void queryEvents(Window& window, Event& event) override;
    
private:
    virtual void initMouseButtons() override;
    void checkMouseButtonPressed(ButtonPair<sf::Mouse::Button>& buttonPair, Event& event);
    void checkMouseButtonReleased(ButtonPair<sf::Mouse::Button>& buttonPair, Event& event);
    void clearEvents();
private:
    // std::unordered_map<char, Key> keyboard;
    std::unordered_map<char, ButtonPair<sf::Mouse::Button> > mouseButtons;
};


#endif //SFML_CONTROLLER_HPP
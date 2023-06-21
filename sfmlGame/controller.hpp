#include <SFML/Graphics.hpp>

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

class Controller
{
public:

	struct KeyboardEvents{
		struct KeyStates{
			bool pressed{};
			bool onHold{};
			bool released{};
		};
		KeyStates mouseLeft;
		KeyStates mouseRight;
		KeyStates w_key;
	};
public:
	Controller();
	~Controller();

	KeyboardEvents getKeyEvents() const { return keyboardEvents;} ;
    void clearPressedEvents();
    void clearReleasedEvents();
    void handleEvents(sf::Event& event, sf::RenderWindow& window);
	void initKeys();
private:
	KeyboardEvents keyboardEvents;
};

#endif //CONTROLLER_HPP
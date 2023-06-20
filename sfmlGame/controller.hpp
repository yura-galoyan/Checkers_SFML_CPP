#include <SFML/Graphics.hpp>

class Controller
{
private:
	struct KeyboardEvents{
		bool mouseLeftButtonPressed{};
		bool mouseLeftButtonOnHold{};
		bool mouseLeftButtonReleased{};

		bool mouseRightButtonPressed{};
		bool mouseRightButtonOnHold{};
		bool mouseRightButtonReleased{};

		bool w_keyPressed{};
		bool w_keyOnHold{};
		bool w_keyReleased{};
	};

public:
	Controller();
	~Controller();


    void clearPressedEvents();
    void handleEvents(sf::Event& event, sf::RenderWindow& window);
	void initKeys();
	KeyboardEvents keyboardEvents;
private:

};

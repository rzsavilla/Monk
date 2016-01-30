#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SFML/Graphics.hpp>

class InputHandler
{
private:
	sf::Vector2i mousePos;
public:
	InputHandler();
	bool bUp, bDown, bLeft, bRight;
	bool bLeftClick, bRightClick, bMiddleClick;
	void updateKeyPress(sf::Keyboard::Key key, bool isPressed);
	void updateMousePress(sf::Mouse::Button button, bool isPressed);
	void updateMousePos(sf::Vector2i position);
};

#endif
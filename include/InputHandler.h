#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SFML/Graphics.hpp>

class InputHandler
{
public:
	sf::Vector2i mousePos;
	InputHandler();
	bool bUp, bDown, bLeft, bRight, bEsc;
	bool bLeftClick, bRightClick, bMiddleClick;
	void updateKeyPress(sf::Keyboard::Key key, bool isPressed);
	void updateMousePress(sf::Mouse::Button button, bool isPressed);
	void updateMousePos(sf::Vector2i position);
};

#endif
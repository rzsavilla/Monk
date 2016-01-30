#ifndef PAUSE_SCREEN_H
#define PAUSE_SCREEN_H

#include <SFML/Graphics.hpp>
#include "InputHandler.h"

class Pause_Screen : public sf::Drawable
{
private:
	sf::RectangleShape button;
public:
	Pause_Screen()
	{
		button.setFillColor(sf::Color::Blue);
		button.setPosition(sf::Vector2f(200, 200));
	}

	void update(InputHandler& input) {
		if (input.bLeftClick) {
			button.setFillColor(sf::Color::Green);
		}
	}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const {
		target.draw(button, states);
	}
};

#endif
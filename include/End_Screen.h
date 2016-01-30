#ifndef END_SCREEN_H
#define END_SCREEN_H


#include "InputHandler.h"
#include <SFML/Graphics.hpp>

class End_Screen : public sf::Drawable
{
private:
	sf::RectangleShape button;
public:
	End_Screen() {
		button.setFillColor(sf::Color::Red);
		button.setPosition(sf::Vector2f(100.f, 100.f));
	}

	void update(InputHandler& input) {
		if (input.bLeftClick) {
			button.setFillColor(sf::Color::Blue);
		}
	}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const {
		target.draw(button, states);
	}
};

#endif
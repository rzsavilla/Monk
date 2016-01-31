#include "How_Screen.h"

How_Screen::How_Screen()
{
	bg.loadFromFile("assets\\screens\\how_background.png");
	background.setTexture(bg);

	next.loadFromFile("assets\\sprites\\play_button.png");
	Next_Button.setTexture(next);
	Next_Button.setOrigin(sf::Vector2f(next.getSize().x / 2, next.getSize().y / 2));
}

void How_Screen::GetWindow(sf::Vector2u windowSize)
{
	Next_Button.setPosition(sf::Vector2f(windowSize.x * 4 / 5, windowSize.y * 3 / 4));
}

int How_Screen::update(InputHandler& input)
{
	int  iNewState = 4;

	if (input.bLeftClick) {
		if (input.mousePos.x > Next_Button.getPosition().x - (next.getSize().x / 2) || input.mousePos.x < Next_Button.getPosition().x + (next.getSize().x / 2))
		{
			if (input.mousePos.y > Next_Button.getPosition().y - (next.getSize().y / 2) || input.mousePos.y < Next_Button.getPosition().y + (next.getSize().y / 2))
			{
				iNewState = 1;
				input.bLeftClick = false;
			}
		}
	}

	return iNewState;
}

void How_Screen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(background, states);
	target.draw(Next_Button, states);
}
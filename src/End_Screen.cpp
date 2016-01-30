#include "End_Screen.h"

End_Screen::End_Screen()
{
	bg.loadFromFile("assets\\sprites\\end_background.png");
	background.setTexture(bg);

	end.loadFromFile("assets\\sprites\\end_button.png");
	End_Button.setTexture(end);
	End_Button.setOrigin(sf::Vector2f(end.getSize().x / 2, end.getSize().y / 2));
}

void End_Screen::GetWindow(sf::Vector2u windowSize)
{
	End_Button.setPosition(sf::Vector2f(windowSize.x / 2, windowSize.y * 3 / 4));
}

int End_Screen::update(InputHandler& input)
{
	int  iNewState = 3;
	//Check button presses
	if (input.bDown) {
		iNewState = 0;
	}

	return iNewState;
}

void End_Screen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(background, states);
	target.draw(End_Button, states);
}
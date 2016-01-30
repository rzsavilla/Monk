#include "End_Screen.h"

End_Screen::End_Screen()
{
	bg.loadFromFile("assets\\sprites\\end_background.png");
	background.setTexture(bg);

	End_Button.setFillColor(sf::Color::Red);
	End_Button.setSize(sf::Vector2f(300, 50));
	End_Button.setOrigin(End_Button.getSize() / 2.f);
}

void End_Screen::GetWindow(sf::Vector2u windowSize)
{
	End_Button.setPosition(sf::Vector2f(windowSize.x / 2, windowSize.y / 2));
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
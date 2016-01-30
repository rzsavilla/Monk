#include "Pause_Screen.h"

Pause_Screen::Pause_Screen()
{
	bg.loadFromFile("assets\\sprites\\pause_background.png");
	background.setTexture(bg);

	Pause_Button.setFillColor(sf::Color::White);
	Pause_Button.setSize(sf::Vector2f(200, 100));
	Pause_Button.setOrigin(Pause_Button.getSize() / 2.f);
}

void Pause_Screen::GetWindow(sf::Vector2u windowSize)
{
	Pause_Button.setPosition(sf::Vector2f(windowSize.x / 2, windowSize.y / 2));
}

int Pause_Screen::update(InputHandler& input)
{
	int  iNewState = 2;
	//Check button presses
	if (input.bUp) {
		iNewState = 1;
	}

	return iNewState;
}

void Pause_Screen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(background, states);
	target.draw(Pause_Button, states);
}
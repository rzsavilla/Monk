#include "Pause_Screen.h"

Pause_Screen::Pause_Screen()
{
	bg.loadFromFile("assets\\screens\\pause_background.png");
	background.setTexture(bg);

	pause.loadFromFile("assets\\sprites\\continue_button.png");
	Pause_Button.setTexture(pause);
	Pause_Button.setOrigin(sf::Vector2f(pause.getSize().x / 2, pause.getSize().y / 2));
}

void Pause_Screen::GetWindow(sf::Vector2u windowSize)
{
	Pause_Button.setPosition(sf::Vector2f(windowSize.x / 2, windowSize.y * 3 / 4));
}

int Pause_Screen::update(InputHandler& input)
{
	int  iNewState = 2;
	//Check button presses, return to play screen
	if (input.bEsc) {
		iNewState = 1;
		input.bEsc = false;
	}

	return iNewState;
}

void Pause_Screen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(background, states);
	target.draw(Pause_Button, states);
}
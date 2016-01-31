#include "Pause_Screen.h"

Pause_Screen::Pause_Screen()
{
	bg.loadFromFile("assets\\screens\\pause_background.png");
	background.setTexture(bg);
}

void Pause_Screen::GetWindow(sf::Vector2u windowSize)
{

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
}
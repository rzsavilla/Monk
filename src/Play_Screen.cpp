#include "Play_Screen.h"

Play_Screen::Play_Screen() {
	bg.loadFromFile("assets\\sprites\\background.png");
	background.setTexture(bg);
}

int Play_Screen::update(InputHandler& input) {
	int iNewState = 1;
	//Check button presses
	if (input.bRight) {
		iNewState = 2;
	}
	else if (input.bLeft) {
		iNewState = 3;
	}

	return iNewState;
}

void Play_Screen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(background, states);
}
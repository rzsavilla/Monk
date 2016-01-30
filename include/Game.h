#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "InputHandler.h"

class Game
{
private:
	InputHandler input;
	sf::RenderWindow window;
	void handleEvents();
	void update();
	void render();
public:
	Game();
	void run();
};

#endif
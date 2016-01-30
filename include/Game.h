#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Start_Screen.h"

class Game
{
private:
	Start_Screen start_screen;
	int iState;
	InputHandler input;
	sf::RenderWindow window;
private:
	void handleEvents();
	void update();
	void render();
public:
	Game();
	void run();
};

#endif
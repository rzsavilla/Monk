#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Start_Screen.h"
#include "Pause_Screen.h"

class Game
{
private:
	Start_Screen start_screen;
	Pause_Screen pause_screen;
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
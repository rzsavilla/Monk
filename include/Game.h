#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "InputHandler.h"
#include "Start_Screen.h"

enum GameState { STARTMENU, RUNNING, PAUSED };

class Game
{
private:
	//Start_Screen start_screen;
	GameState gameState;
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
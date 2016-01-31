#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Start_Screen.h"
#include "How_Screen.h"
#include "Pause_Screen.h"
#include "End_Screen.h"
#include "Play_Screen.h"
#include "Spawner.h"
#include "Entity.h"

class Game
{
private:
	int iState;
	Start_Screen start_screen;					// State 0
	Play_Screen play_screen;					// State 1
	Pause_Screen pause_screen;					// State 2
	End_Screen end_screen;						// State 3
	How_Screen how_screen;						// State 4
	InputHandler input;
	sf::RenderWindow window;
	sf::Clock timer;
private:
	void handleEvents();
	void update(sf::Time h);
	void render();
public:
	Game();
	void run();
};

#endif
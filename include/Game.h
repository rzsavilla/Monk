#ifndef GAME_H
#define GAME_H

class Game
{
private:
	void handleEvents();
	void update();
	void render();
public:
	Game();
	run();
}

#endif
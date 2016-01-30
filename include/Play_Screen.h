#ifndef PLAY_SCREEN_H
#define PLAY_SCREEN_H

#include <SFML/Graphics.hpp>
#include "InputHandler.h"
#include "Spawner.h"

class Play_Screen: public sf::Drawable
{
private:
	Spawner spawner;
	Entity enemy;
	sf::Texture texture;
	sf::Sprite background;
	sf::Texture bg;
public:
	Play_Screen();
	int update(sf::Time h,InputHandler& input);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
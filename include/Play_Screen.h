/*

#ifndef PLAY_SCREEN_H
#define PLAY_SCREEN_H

#include <SFML/Graphics.hpp>
#include "InputHandler.h"
#include "Spawner.h"

#include "MonkGroup.h"

class Play_Screen: public sf::Drawable
{
private:
	Spawner spawner;
	Entity enemy;
	sf::Texture texture;
	sf::Sprite background;
	sf::Texture bg;
	MonkGroup monkGroup;
public:
	Play_Screen();
	int update(sf::Time h,InputHandler& input);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif

*/

#ifndef PLAY_SCREEN_H
#define PLAY_SCREEN_H

#include <SFML/Graphics.hpp>
#include "InputHandler.h"
#include "Spawner.h"
#include "Entity.h"
#include "MonkGroup.h"

class Play_Screen : public sf::Drawable
{
private:
	int iScore;

	Entity monk;
	Entity enemy;
	MonkGroup monk_Group;
	sf::Texture texture;
	sf::Texture bg;
	sf::Sprite background;
	Spawner spawner;
public:
	Play_Screen();
	int update(sf::Time h, InputHandler& input);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void initialize();
};

#endif
#ifndef SPAWNER_H
#define SPAWNER_H

#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include "Entity.h"

class Spawner: public sf::Drawable
{
private:
	sf::CircleShape toSpawn;
	int iNumPoints;
	float fRadius;
	sf::Vector2f position;
	std::vector<sf::Vector2f> Points;

	Entity entity;

	bool bSpawning;
	void createPoints();
public:
	Spawner();
	void setPoints(int num);
	void setRadius();
	void setPosition(sf::Vector2f position);
	void setSpawn(sf::CircleShape& shape);
	void update(sf::Time h);

	void spawn();									//Start Spawning
	bool isFinished();
};

#endif
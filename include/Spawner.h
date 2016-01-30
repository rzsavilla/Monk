#ifndef SPAWNER_H
#define SPAWNER_H

#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Spawner: public sf::Drawable
{
private:
	std::vector<Entity> entitiesSpawned;
	float fRadius;
	int iNumPoints;									//Number of positions to spawn from
	sf::Vector2f position;							//Position of Spawner/Origin
	std::vector<sf::Vector2f> Points;				//Positions to spawn from
	void createPoints();							//Create the position points
	int iSpawnCount;								//Number of Entities to spawn
	Entity spawnEntity;									//Entity that will be spawned
	bool bSpawning;									//If Spawner is currently spawning

	void randGenerate();							//Generate list of random numbers
	std::vector<int> randomPosition;

public:
	Spawner();
	void setPoints(int num);
	void setRadius(float Radius);
	void setPosition(sf::Vector2f position);
	void setSpawn(Entity& entity);
	void update(sf::Time h);
	void spawn();									//Start Spawning
	bool isFinished();
};

#endif
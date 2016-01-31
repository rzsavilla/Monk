#ifndef SPAWNER_H
#define SPAWNER_H

#define _USE_MATH_DEFINES

#include <memory>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <vector>

class InputHandler;

class Spawner: public sf::Drawable
{
private:
	
	float fRadius;
	int iNumPoints;									//Number of positions to spawn from
	sf::Vector2f position;							//Position of Spawner/Origin
	std::vector<sf::Vector2f> Points;				//Positions to spawn from
	void createPoints();							//Create the position points
	int iSpawnCount;								//Number of Entities to spawn
	int iCounter;
	Entity spawnEntity;									//Entity that will be spawned
	bool bSpawning;									//If Spawner is currently spawning

	void randGenerate();							//Generate list of random numbers
	std::vector<int> randomPosition;
	std::vector<Entity> entitiesSpawned;

public:
	
	Spawner();
	void setPoints(int num);
	void setRadius(float Radius);
	void setPosition(sf::Vector2f position);
	void setSpawn(Entity& entity);
	void update(sf::Time h, InputHandler& input, int& score);
	void spawn();									//Start Spawning

	void collideMonks(std::vector<Entity>& monks);	//IMpulse Collision with monks
	void updateMoveTo();
	void selfCollide();
	bool isFinished();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
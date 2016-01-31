#ifndef MONKGROUP_H
#define MONKGROUP_H

#define _USE_MATH_DEFINES

#include "Entity.h"

#include <SFML/Graphics.hpp>

/*
Group of Monks
Will handle the group of monks
*/

class MonkGroup : public sf::Drawable
{
private:
	Entity monkSpawn;
	sf::Texture texture;
	sf::Vector2f Position;					//Centre of circle
	int iMonkNum;							//Number of monks in a circle
	float fRadius;
	void createMonks();					//Positions monks around centre position, monks will move towards target
	

	void RotateMonks(float fDegrees);
public:
	std::vector<Entity> Monks;
	MonkGroup::MonkGroup();

	void setRadius(float radius);
	void setMonkCount(int Num);
	void setPosition(sf::Vector2f pos);

	void selfCollide();
	void updateMoveT();
	void allImpulseCollide(Entity& entity);		//Check group collision with object

	void update(sf::Time h);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
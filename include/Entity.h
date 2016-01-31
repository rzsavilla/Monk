#ifndef ENTITY_H
#define ENTITY_H
#include "Moveable.h"
#include <SFML/Graphics/CircleShape.hpp>

class Entity : public sf::Sprite, public Moveable
{
private:
	float fe;					//Coefficient of resitution
	float fRadius;
public:
	Entity();
	void update(sf::Time h);
	sf::Vector2f moveTowards(sf::Vector2f target);
	bool Collides(Entity other);			//Check collision with circle
	bool impulseCollision(Entity& other);
	void setE(float e){
		fe = e;
	}

	void setRadius(float Radius) { fRadius = Radius; }
	float getRadius() { return fRadius; }
};

#endif
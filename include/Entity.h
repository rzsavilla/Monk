#ifndef ENTITY_H
#define ENTITY_H


#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Moveable.h"
#include "Collision2D.h"
#include "Health.h"

class Entity : public Moveable, public sf::Sprite, public Collision2D, public Health
{
public:
	Entity();
private:
	void update(sf::Time h);
};

#endif
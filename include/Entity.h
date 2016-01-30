#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics/Sprite.hpp>
#include "Moveable.h"

class Entity : public Moveable, public sf::Sprite
{
public:
	Entity(int health);
	void modifyHealth(int amount);
private:
	int m_health;
};

#endif
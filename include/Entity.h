#ifndef ENTITY_H
#define ENTITY_H

#include "Moveable.h"

class Entity : public Moveable
{
public:
	Entity(int health);
	void modifyHealth(int amount);
private:
	int m_health;
};

#endif
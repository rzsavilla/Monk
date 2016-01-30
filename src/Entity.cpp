#include "Entity.h"

Entity::Entity(int health) : Moveable()
{
	// Initialisation
	m_health = health;
}

void Entity::modifyHealth(int amount)
{
	m_health += amount;
}
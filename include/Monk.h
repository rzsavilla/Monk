#ifndef MONK_H
#define MONK_H

#include <memory>
#include "Entity.h"

class Enemy;

class Monk : public Entity
{
public:
	Monk(int defensePower, int health);
	void defend(Enemy& enemy);
private:
	const int m_defensePower;
};

#endif
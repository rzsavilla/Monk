/*
#ifndef ENEMY_H
#define ENEMY_H

#include <memory>
#include "Entity.h"

class Monk;

class Enemy : public Entity
{
public:
	Enemy(float attackinterval, int attackPower, int health);
	int getAttackPower();
	void attack(Monk& monk, float deltaTime);
private:
	const int m_attackPower;
	const float m_attackInterval;
	float m_lastAttackTime;
};

#endif
*/
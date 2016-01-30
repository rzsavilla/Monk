#include "Enemy.h"
#include "Monk.h"

Enemy::Enemy(float attackInterval, int attackPower, int health) : m_attackInterval(abs(attackInterval)), m_attackPower(abs(attackPower)), Entity(health) {}

int Enemy::getAttackPower()
{
	return m_attackPower;
}

void Enemy::attack(Monk& monk, float deltaTime)
{
	// Update the time variable
	m_lastAttackTime += deltaTime;
	// Check the time since the last attack
	if (m_lastAttackTime >= m_attackInterval)
	{
		// Attack
		monk.defend(*this);
	}
}
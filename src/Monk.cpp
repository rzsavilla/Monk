#include "Monk.h"
#include "Enemy.h"

Monk::Monk(int defensePower, int health) : m_defensePower(defensePower), Entity(health) {}

void Monk::defend(Enemy& enemy)
{
	this->modifyHealth(m_defensePower / enemy.getAttackPower());
}
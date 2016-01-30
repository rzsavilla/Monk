#ifndef HEALTH_H
#define HEALTH_H

class Health {
private:
	int iHealth;
	int iMaxHealth;
	bool bDead;
public:
	void setHealth(int Health);
	void setMaxHealth(int MaxHealth);
	bool isDead();
};

#endif
#ifndef MOVEABLE_H
#define MOVEABLE_H

#include <SFML/System/Vector2.hpp>

class Moveable
{
private:
	sf::Vector2f vPos;
	float fSpeed;
	float fMaxSpeed;
	float fAccel;
	sf::Vector2f vTarget;
public:
	Moveable();
	void SetTarget(sf::Vector2f target);
	void Update();
};

#endif
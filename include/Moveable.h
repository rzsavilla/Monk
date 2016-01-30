#ifndef MOVEABLE_H
#define MOVEABLE_H

#include <SFML/System/Vector2.hpp>
#include <iostream>
class Moveable
{
private:
	sf::Vector2f vPos;
	float fSpeed;
	float fMaxSpeed;
	float fAccel;
	sf::Vector2f vTarget;
protected:
	sf::Vector2f fVelo;
public:
	Moveable();
	void SetPos(sf::Vector2f pos) {
		vPos = pos;
		std::cout << pos.x << std::endl;
	}
	void SetSpeed(float speed);
	void SetMaxSpeed(float maxSpeed);
	void SetAccel(float accel);
	void SetTarget(sf::Vector2f target);
	sf::Vector2f Update();
};

#endif
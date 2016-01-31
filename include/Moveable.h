#ifndef MOVEABLE_H
#define MOVEABLE_H

#include <SFML/Graphics.hpp>
#include "Maths2D.h"
class Moveable {
protected:
	sf::Vector2f TargetPos;
	bool bHasTarget;

	float fMass;
	float fFriction;

	float fAcceleration;		//Increments Speed
	float fSpeed;				//Current Speed
	float fMaxSpeed;

	sf::Vector2f velocity;
public:
	void moveTowards(sf::Vector2f position);		//Will use acceleration to change velocity to move towards target

	void setMass(float Mass);
	void setFriction(float Friction);
	void setAcceleration(float Acceleration);
	void setSpeed(float Speed);
	void setMaxSpeed(float MaxSpeed);
	void setVelocity(sf::Vector2f vel);

	void setTargetPos(sf::Vector2f targetPos);

	float getMass();
	float getFriction();
	float getAcceleration();
	float getSpeed();
	float getMaxSpeed();
	sf::Vector2f getVelocity();
	sf::Vector2f getTargetPos();

	bool hasTarget();

};

#endif

/*
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
	}
	void SetSpeed(float speed);
	void SetMaxSpeed(float maxSpeed);
	void SetAccel(float accel);
	void SetTarget(sf::Vector2f target);
	sf::Vector2f Update();
	void setVelocity(sf::Vector2f velocity);
};

#endif

*/
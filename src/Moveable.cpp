#include "Moveable.h"
#include "Maths2D.h"

void Moveable::setMass(float Mass) { fMass = Mass; };
void Moveable::setFriction(float Friction) { fFriction = Friction; }
void Moveable::setAcceleration(float Acceleration) { fAcceleration = Acceleration; }
void Moveable::setSpeed(float Speed) { fSpeed = Speed; }
void Moveable::setMaxSpeed(float MaxSpeed) { fMaxSpeed = MaxSpeed; }
void Moveable::setVelocity(sf::Vector2f vel) { velocity = vel; }

void  Moveable::setTargetPos(sf::Vector2f targetPos) { TargetPos = targetPos; bHasTarget = true; }

float Moveable::getMass() { return fMass; }
float Moveable::getFriction() { return fFriction; }
float Moveable::getAcceleration() { return fAcceleration; }
float Moveable::getSpeed() { return fSpeed; }
float Moveable::getMaxSpeed() { return fMaxSpeed; }

sf::Vector2f  Moveable::getVelocity() { return velocity; }
sf::Vector2f  Moveable::getTargetPos() { return TargetPos; }
bool Moveable::hasTarget() { return bHasTarget; }

/*
Moveable::Moveable()
{
	//Set proper vars
	fSpeed = 0;
	fMaxSpeed = 10;
	fAccel = 2;
	//Set target first time as the sacrificee
	vTarget = sf::Vector2f();
}

void Moveable::SetSpeed(float speed)
{
	fSpeed = speed;
}

void Moveable::SetMaxSpeed(float maxSpeed)
{
	fMaxSpeed = maxSpeed;
}

void Moveable::SetAccel(float accel)
{
	fAccel = accel;
}

void Moveable::SetTarget(sf::Vector2f target)
{
	vTarget = target;
}

sf::Vector2f Moveable::Update()
{
	fSpeed += fAccel;
	if (fSpeed > fMaxSpeed)
	{
		fSpeed = fMaxSpeed;
	}
	sf::Vector2f hello = Maths2D::UnitVector(vTarget - vPos) * fSpeed;
	fVelo = hello;
	return fVelo;
}

void Moveable::setVelocity(sf::Vector2f velocity) {
	fVelo = velocity;
}
*/
#include "Moveable.h"
#include "Maths2D.h"

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
	//std::cout << "X: " << vPos.x << "\t Y:" << vPos.y << std::endl;
	return fVelo;
}
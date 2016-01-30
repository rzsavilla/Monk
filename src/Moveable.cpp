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

void Moveable::SetTarget(sf::Vector2f target)
{
	vTarget = target;
}

void Moveable::Update()
{
	fSpeed += fAccel;
	if (fSpeed > fMaxSpeed)
	{
		fSpeed = fMaxSpeed;
	}

	vPos += Maths2D::UnitVector(vTarget - vPos) * fSpeed;

}
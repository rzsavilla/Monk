#include "Entity.h"
#include <iostream>

#include "Entity.h"
#include <iostream>
Entity::Entity()
{
	velocity = sf::Vector2f(0, 0);
	fAcceleration = 1.f;
	fSpeed = 0.f;
	fMaxSpeed = 0.f;
	fFriction = 0.f;
	fMass = 20;
	bHasTarget = false;
	TargetPos = sf::Vector2f(100, 100);

	float fRadius;
}

sf::Vector2f Entity::moveTowards(sf::Vector2f target) {		//Will use acceleration to change velocity to move towards target
	fSpeed += fAcceleration;

	if (fSpeed > fMaxSpeed)
	{
		fSpeed = fMaxSpeed;
	}
	velocity = Maths2D::UnitVector(target - getPosition()) * fSpeed;
	
	return velocity;
}

bool Entity::Collides(Entity other) {
	// Check for a collision between the two circles
	sf::Vector2f kfCenterSubtraction = getPosition() - other.getPosition();
	float kfMagnitude = Maths2D::Magnitude(kfCenterSubtraction);
	float kfRadiiSum = getRadius() + other.getRadius();
	return kfMagnitude < kfRadiiSum;
}

bool Entity::impulseCollision(Entity& other) {
	//Check for collision
	if (Collides(other)) {										//Check for collision
		//Calculate Impulse Collision
		float fe = -(1.f + 100); //Coefficient of restitution
		sf::Vector2f diff(getPosition() - other.getPosition());	//Difference in position
		sf::Vector2f normal = Maths2D::UnitVector(diff);		//Unit Normal
		sf::Vector2f diffVel(velocity - other.velocity);				//diffrence in velocity
		float VelDotNorm = (normal.x * diffVel.x) + (normal.y * diffVel.y);			//Dot product of unit normal and velocity
		float massDiv = (1 / getMass() + 1 / other.getMass());
		float j = (fe * VelDotNorm) * massDiv;

		sf::Vector2f jn1 = (normal * j) / getMass();
		sf::Vector2f jn2 = (normal * j) / other.getMass();

		//Apply new velocity
		this->setVelocity(velocity + jn1);
		other.setVelocity(other.velocity - jn2);
		return true;
	}
	else {
		return false;
	}
}

void Entity::update(sf::Time h) {
	move(velocity * h.asSeconds());
}

/*
Entity::Entity() {

}

void Entity::update(sf::Time h) {
	SetPos(getPosition());
	move(Moveable::Update() * h.asSeconds());
}

bool Entity::impulseCollision(Entity& other) {
	//Check for collision
	if (this->getGlobalBounds().intersects(other.getGlobalBounds())) {			//Check for collision
		//Calculate Impulse Collision
		float fe = -(1.f + 1.6); //Coefficient of restitution
		float fMass = 10;
		sf::Vector2f diff(this->getPosition() - other.getPosition());	//Difference in position
		sf::Vector2f normal = Maths2D::UnitVector(diff);		//Unit Normal
		sf::Vector2f diffVel(fVelo - other.fVelo);				//diffrence in velocity
		float VelDotNorm = (normal.x * diffVel.x) + (normal.y * diffVel.y);			//Dot product of unit normal and velocity
		float massDiv = (1 / fMass + 1 / fMass);
		float j = (fe * VelDotNorm) * massDiv;

		sf::Vector2f jn1 = (normal * j) / fMass;
		sf::Vector2f jn2 = (normal * j) / fMass;

		//Set New Velocity of collided entities
		this->setVelocity(this->fVelo + jn1);
		other.setVelocity(other.fVelo - jn2);
		return true;
	}
	else {
		return false;
	}
}
*/
#include "Entity.h"
#include <iostream>
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
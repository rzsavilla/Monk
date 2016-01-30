#include "Entity.h"
#include <iostream>
Entity::Entity() {

}

void Entity::update(sf::Time h) {
	SetPos(getPosition());
	std::cout << getPosition().x << std::endl;
	move(Moveable::Update() * h.asSeconds());
	
}
#include "Entity.h"
#include <iostream>
Entity::Entity() {

}

void Entity::update(sf::Time h) {
	SetPos(getPosition());
	move(Moveable::Update() * h.asSeconds());
}
#include "Entity.h"

Entity::Entity() {

}

void Entity::update(sf::Time h) {
	move(fVelo * h.asSeconds());
}
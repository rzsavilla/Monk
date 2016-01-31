#include "Play_Screen.h"
#include <iostream>

Play_Screen::Play_Screen() {
	bg.loadFromFile("assets\\sprites\\background.png");
	background.setTexture(bg);

	texture.loadFromFile("assets/sprites/monk.png");

	monk.setTexture(texture);
	monk.setPosition(640, 320);
	monk.setSpeed(100.f);
	monk.setMaxSpeed(100.f);
	monk.setRadius(monk.getGlobalBounds().width / 2);
	monk.setOrigin(monk.getGlobalBounds().width / 2, monk.getGlobalBounds().width / 2);

	enemy.setTexture(texture);
	enemy.setPosition(640, 500);
	enemy.setSpeed(100.f);
	enemy.setMaxSpeed(100.f);
	enemy.setRadius(50.f);

	monk_Group.setMonkCount(10);

	spawner.setPoints(20);
	spawner.setRadius(720);
	spawner.setSpawn(monk);
	
	spawner.setPosition(sf::Vector2f(640, 360));
	spawner.spawn();
}

int Play_Screen::update(sf::Time h,InputHandler& input) {
	int iNewState = 1;
	monk_Group.updateMoveT();
	spawner.updateMoveTo();
	//Set/Changes velocity
	monk_Group.selfCollide();
	
	spawner.selfCollide();
	spawner.collideMonks(monk_Group.Monks);

	//Move using velocity
	spawner.update(h,input);
	monk_Group.update(h);
	return iNewState;
}

void Play_Screen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(monk_Group, states);
	target.draw(spawner, states);
	//target.draw(monk, states);
	//target.draw(enemy, states);
	
}
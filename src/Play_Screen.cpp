#include "Play_Screen.h"
#include <iostream>
Play_Screen::Play_Screen() {
	bg.loadFromFile("assets\\sprites\\background.png");
	background.setTexture(bg);

	texture.loadFromFile("assets/sprites/monk.png");
	enemy.setTexture(texture);
	enemy.SetSpeed(100.f);
	enemy.SetMaxSpeed(100.f);
	enemy.SetTarget(sf::Vector2f(100, 100));
	enemy.setPosition(100.f, 100.f);

	//////Spawner Test
	spawner.setRadius(100);
	spawner.setPoints(10);
	spawner.setPosition(sf::Vector2f(sf::Vector2f(1280 / 2,720 / 2)));
	spawner.setSpawn(enemy);
	spawner.spawn();

	/////////Monks Group Test
}

int Play_Screen::update(sf::Time h,InputHandler& input)
{
	spawner.update(h, input);
	monkGroup.update(h);
	int iNewState = 1;
	//Check button presses
	if (input.bEsc) {
		iNewState = 2;
		input.bEsc = false;
	}
	else if (input.bLeft) {
		iNewState = 3;
	}

	return iNewState;
}

void Play_Screen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//target.draw(enemy,states);
	target.draw(monkGroup, states);
	target.draw(spawner, states);
	//target.draw(background, states);
}
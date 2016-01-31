#include "MonkGroup.h"
#include <iostream>
MonkGroup::MonkGroup() {
	texture.loadFromFile("assets/sprites/monk.png");
	monkSpawn.setTexture(texture);
	monkSpawn.setSpeed(100);
	monkSpawn.setAcceleration(1.0f);
	monkSpawn.setMaxSpeed(0);
	monkSpawn.setRadius(monkSpawn.getGlobalBounds().width / 2);
	monkSpawn.setOrigin(monkSpawn.getRadius(), monkSpawn.getRadius());
	monkSpawn.setScale(2.f, 2);
	iMonkNum = 8;
	fRadius = 120;
	Position = sf::Vector2f(640, 360);
	//createMonks();
}

MonkGroup::MonkGroup(sf::Vector2f position, int NumberOfMonks, float fRadius) {

}

void MonkGroup::createMonks() {
	float fdetlaT = (2 * M_PI) / (float)(iMonkNum);
	float t = 0;
	for (int i = 0; i < iMonkNum; i++) {
		sf::Vector2f targetPosition = sf::Vector2f(fRadius * cos(t) + Position.x, fRadius * sin(t) + Position.y);
		//std::cout << targetPosition.y << std::endl;
		Monks.push_back(monkSpawn);
		Monks.back().setPosition(targetPosition);		//Spawns monk onto position
		Monks.back().setTargetPos(targetPosition + sf::Vector2f(0.1,0.1));			//Monks will move towards target		
		//Monks.back().setTargetPos(sf::Vector2f(100,300.f));			//Monks will move towards target
		t += fdetlaT;
	}
}

void MonkGroup::setRadius(float radius) {
	fRadius = radius;
}

void MonkGroup::setMonkCount(int Num) {
	iMonkNum = Num;
	Monks.clear();
	Monks.resize(iMonkNum);
	createMonks();
}

void MonkGroup::setPosition(sf::Vector2f position) {
	Position = position;
}

void  MonkGroup::selfCollide() {
	for (int i = 0; i < Monks.size(); i++) {
		for (int j = i + 1; j < Monks.size(); j++) {
			if (Monks.at(i).impulseCollision(Monks.at(j))) {
				//std::cout << "Collision\n";
			}
		}
	}
}
void  MonkGroup::updateMoveT() {
	for (int i = 0; i < Monks.size(); i++) {
		Monks.at(i).moveTowards(Monks.at(i).getTargetPos());
	}
}

void MonkGroup::update(sf::Time h) 
{
	for (int i = 0; i < Monks.size(); i++) {
		Monks[i].update(h);
		Monks[i].rotate(100.f * h.asSeconds());
	}
}

void MonkGroup::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (int i = 0; i < Monks.size(); i++) {
		target.draw(Monks[i], states);
	}
}
#include "MonkGroup.h"
#include <iostream>
MonkGroup::MonkGroup() {
	texture.loadFromFile("assets/sprites/monk.png");
	monkSpawn.setTexture(texture);
	monkSpawn.setSpeed(0);
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

void MonkGroup::createMonks() {
	float fdetlaT = (2 * M_PI) / (float)(iMonkNum);
	float t = 0;
	for (int i = 0; i < iMonkNum; i++) {
		sf::Vector2f targetPosition = sf::Vector2f(fRadius * cos(t) + Position.x, fRadius * sin(t) + Position.y);
		int rotation = 180 - (i * -36);
		if (rotation > 360) 
			rotation -= 360;
		monkSpawn.rotate(rotation);
		//std::cout << targetPosition.y << std::endl;
		Monks.push_back(monkSpawn);
		Monks.back().setPosition(targetPosition);		//Spawns monk onto position
		Monks.back().setTargetPos(targetPosition + sf::Vector2f(0.1,0.1));			//Monks will move towards target		
		//Monks.back().setTargetPos(sf::Vector2f(100,300.f));			//Monks will move towards target
		t += fdetlaT;
	}
}

void MonkGroup::RotateMonks(float fDegrees) {
	float fRadians = fDegrees * Maths2D::PI / 180;
	
	sf::Vector2f rotationPoint = sf::Vector2f(640, 360);
	for (int i = 0; i < Monks.size(); i++)
	{
		sf::Vector2f monkPosition = Monks.at(i).getPosition();
		float sin = sinf(fRadians);
		float cos = cosf(fRadians);

		// Translate the point
		monkPosition -= rotationPoint;
		// Rotate the point
		float xNew = monkPosition.x * cos - monkPosition.y * sin;
		float yNew = monkPosition.x * sin + monkPosition.y * cos;
		// Translate the point back
		monkPosition = sf::Vector2f(xNew + rotationPoint.x, yNew + rotationPoint.y);

		// Set the position
		Monks.at(i).setPosition(monkPosition);
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
	RotateMonks(10 * h.asSeconds());
	for (int i = 0; i < Monks.size(); i++) {
		Monks[i].update(h);
	}
}

void MonkGroup::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (int i = 0; i < Monks.size(); i++) {
		target.draw(Monks[i], states);
	}
}
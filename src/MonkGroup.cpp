#include "MonkGroup.h"

MonkGroup::MonkGroup() {
	monkTexture.loadFromFile("assets/sprites/monk.png");
	monk.setTexture(monkTexture);
	monk.SetSpeed(100);
	monk.SetMaxSpeed(100);
	iMonkNum = 5;
	fRadius = 100;
	Position = sf::Vector2f(640, 360);
	createMonks();
}

MonkGroup::MonkGroup(sf::Vector2f position, int NumberOfMonks, float fRadius) {

}

void MonkGroup::createMonks() {
	float fdetlaT = (2 * M_PI) / (float)(iMonkNum);
	float t = 0;
	for (int i = 0; i < iMonkNum; i++) {
		sf::Vector2f targetPosition = sf::Vector2f(fRadius * cos(t) + Position.x, fRadius * sin(t) + Position.y);
		//std::cout << targetPosition.y << std::endl;
		Monks.push_back(monk);
		Monks.back().setPosition(targetPosition);		//Spawns monk onto position
		Monks.back().SetTarget(targetPosition + sf::Vector2f(50.f,50.f));			//Monks will move towards target
		//Monks.back().SetTarget(sf::Vector2f(100,300.f));			//Monks will move towards target
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

void MonkGroup::update(sf::Time h) {
	for (int i = 0; i < Monks.size(); i++) {
		Monks[i].update(h);
	}
	for (int i = 0; i < Monks.size(); i++) {
		for (int j = 1; j < Monks.size(); j++) {
			//if (Monks.at(i).impulseCollision(Monks.at(j))) {
				//std::cout << "Collision\n";
			//}
		}
	}
}

void MonkGroup::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (int i = 0; i < Monks.size(); i++) {
		target.draw(Monks[i], states);
	}
}
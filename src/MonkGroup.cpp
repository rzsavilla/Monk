#include "MonkGroup.h"

MonkGroup::MonkGroup() {
	monkTexture.loadFromFile("assets/sprites/monk.png");
	monk.setTexture(monkTexture);
	monk.SetSpeed(10);
	monk.SetMaxSpeed(100);
	iMonkNum = 10;
	fRadius = 100.f;
	Position = sf::Vector2f(640, 360);
	createMonks();
	//std::cout << "Monks created\n";
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
		Monks.back().SetTarget(targetPosition);			//Monks will move towards target
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
		Monks[i].Update();
	}
}

void MonkGroup::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (int i = 0; i < Monks.size(); i++) {
		target.draw(Monks[i], states);
	}
}
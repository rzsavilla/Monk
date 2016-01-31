#include "Spawner.h"
#include "InputHandler.h"
#include <iostream>
Spawner::Spawner() {
	bSpawning = false;
	//iSpawnCount = 10;
}

void Spawner::createPoints() {					//Generate Spawning Positions
	Points.resize(iNumPoints);
	sf::Vector2f pos = position;
	float fdetlaT = (2 * M_PI) / (float)(iNumPoints);
	float t = 0;
	for (int i = 0; i < iNumPoints; i++) {
		Points[i].x = (fRadius * (cos(t))) + pos.x;
		Points[i].y = (fRadius * (sin(t))) + pos.y;
		t += fdetlaT;
	}
}

void Spawner::setPoints(int num) {
	iNumPoints = num;
}
void Spawner::setRadius(float Radius) {
	fRadius = Radius;
}
void Spawner::setPosition(sf::Vector2f Position) {
	position = Position;
}
void Spawner::setSpawn(Entity& entity) {
	spawnEntity = entity;
}

void Spawner::setSpawnCount(int i) {
	if (i >= iNumPoints) {
		iSpawnCount = i;
	}
}

void Spawner::update(sf::Time h, InputHandler& input, int& score) {
	// Check for clicks
	std::shared_ptr<sf::RectangleShape> pMouseArea = nullptr;
	if (input.bLeftClick)
	{
		pMouseArea = std::shared_ptr<sf::RectangleShape>(new sf::RectangleShape);
		pMouseArea->setSize(sf::Vector2f(5, 5));
		sf::Vector2i mousePosition = input.mousePos;
		pMouseArea->setPosition(mousePosition.x, mousePosition.y);
	}

	// Update velocity
	for (int i = 0; i < entitiesSpawned.size(); i++) {
		entitiesSpawned.at(i).update(h);
		// Check for kills
		if (pMouseArea != nullptr && entitiesSpawned.at(i).getGlobalBounds().intersects(pMouseArea->getGlobalBounds()))
		{
			// Kill
			entitiesSpawned.erase(entitiesSpawned.begin() + i);
			// Update score
			score += 10;
		}
	}
}

void Spawner::spawn() {
	createPoints();
	bSpawning = true;
	randGenerate();
	std::cout << "Spawn\n";
	for (int i = 0; i < iSpawnCount; i++) {
		entitiesSpawned.push_back(spawnEntity);
		entitiesSpawned.back().setPosition(Points[randomPosition[i]]);
		entitiesSpawned.back().setTargetPos(sf::Vector2f(640, 360));
	}

}									//Start Spawning


void Spawner::collideMonks(std::vector<Entity>& monks) {
	if (monks.size() > 0) {
		for (int i = 0; i < entitiesSpawned.size(); i++) {
			for (int j = 0; j < monks.size(); j++) {
				if (!monks.empty()) {
					if (!(i > monks.size() - 1))
					{
						if (entitiesSpawned.at(i).Collides(monks.at(j))) {
							monks.erase(monks.begin() + i);
						}
					}
				}
			}
		}
	}
}
void Spawner::updateMoveTo() {
	for (int i = 0; i < entitiesSpawned.size(); i++) {
		entitiesSpawned[i].moveTowards(entitiesSpawned.at(i).getTargetPos());
	}
}

void Spawner::selfCollide() {
	for (int i = 0; i < entitiesSpawned.size(); i++) {
		for (int j = i + 1; j < entitiesSpawned.size(); j++) {
			if (entitiesSpawned.at(i).impulseCollision(entitiesSpawned.at(j))) {
				std::cout << "Collision\n";
			}
		}
	}
}
bool Spawner::isFinished() {
	if (bSpawning) {
		return false;
	}
	else {
		return true;
	}
}

void Spawner::randGenerate() {
	srand(time(NULL)); //always seed your RNG before using it

	for (int i = 0; i<iSpawnCount; i++)								//generate random numbers:
	{
		bool check;														//variable to check or number is already used
		int n;															//variable to store the number in
		do
		{
			n = rand() % iNumPoints;
			//check or number is already used:
			check = true;
			for (int j = 0; j<i; j++)
			if (n == randomPosition[j]) //if number is already used
			{
				check = false; //set check to false
				break; //no need to check the other elements of value[]
			}
		} while (!check); //loop until new, unique number is found
		randomPosition.push_back(n); //store the generated number in the array
	}
	//at this point in the program we have an array value[] with a serie of unique random numbers 
}

void Spawner::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (int i = 0; i < entitiesSpawned.size(); i++) {
		target.draw(entitiesSpawned[i], states);
	}
}
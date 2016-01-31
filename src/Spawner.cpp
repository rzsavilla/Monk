#include "Spawner.h"
#include "InputHandler.h"
#include <iostream>

Spawner::Spawner() {
	bSpawning = false;
	iSpawnCount = 10;
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
void Spawner::update(sf::Time h, InputHandler& input) {
	// Check for clicks
	std::shared_ptr<sf::RectangleShape> pMouseArea = nullptr;
	if (input.bLeftClick)
	{
		pMouseArea = std::shared_ptr<sf::RectangleShape>(new sf::RectangleShape());
		pMouseArea->setSize(sf::Vector2f(5, 5));
		sf::Vector2i mousePosition = input.mousePos;
		pMouseArea->setPosition(mousePosition.x, mousePosition.y);
	}

	for (int i = 0; i < entitiesSpawned.size(); i++)
	{
		entitiesSpawned.at(i).update(h);
		// Check for clicks and drags
		if (pMouseArea != nullptr && entitiesSpawned.at(i).getGlobalBounds().intersects(pMouseArea->getGlobalBounds()))
			// Drag entity
			entitiesSpawned.at(i).setPosition(pMouseArea->getPosition());
	}
}

void Spawner::spawn() {
	createPoints();
	bSpawning = true;
	randGenerate();
	
	for (int i = 0; i < iSpawnCount; i++) {
		entitiesSpawned.push_back(spawnEntity);
		entitiesSpawned.back().setPosition(Points[randomPosition[i]]);
	}
	
}									//Start Spawning
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
	
	for (int i = 0; i<iSpawnCount ; i++)								//generate random numbers:
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
	for (int i = 0; i < entitiesSpawned.size();i++) {
		target.draw(entitiesSpawned[i],states);
	}
}
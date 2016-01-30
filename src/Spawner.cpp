#include "Spawner.h"

Spawner::Spawner() {
	
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
void Spawner::update(sf::Time h) {
	if (bSpawning) {
		for (int i = 0; i < iSpawnCount; i++) {
			entitiesSpawned.push_back(spawnEntity);
			spawnEntity.setPosition(Points[randomPosition[i]]);
		}
	}
}

void Spawner::spawn() {
	bSpawning = true;
	randGenerate();
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

	//generate random numbers:
	for (int i = 0; i<iSpawnCount ; i++)
	{
		bool check; //variable to check or number is already used
		int n; //variable to store the number in
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
		randomPosition[i] = n; //store the generated number in the array
	}
	//at this point in the program we have an array value[] with a serie of unique random numbers 
}
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
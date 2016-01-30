#ifndef SPAWNER_H
#define SPAWNER_H

#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>


class Spawner: public sf::Drawable
{
private:
	int iNumPoints;
	float fRadius;
	sf::Vector2f position;
	std::vector<sf::Vector2f> Points;

	void createPoints();

public:
	Spawner();

	void setPoints(int num);
	void setRadius();
	void setPosition(sf::Vector2f position);


	void update(sf::Time h);
};

#endif
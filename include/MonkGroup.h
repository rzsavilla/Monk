#ifndef MONKGROUP_H
#define MONKGROUP_H

#define _USE_MATH_DEFINES

#include "Entity.h"

#include <SFML/Graphics.hpp>

/*
	Group of Monks
	Will handle the group of monks
*/

class MonkGroup: public sf::Drawable 
{
private:
	Entity monk;
	sf::Texture monkTexture;				//Texture
	sf::Vector2f Position;					//Centre of circle
	int iMonkNum;							//Number of monks in a circle
	float fRadius;
	void createMonks();					//Positions monks around centre position, monks will move towards target
	std::vector<Entity> Monks;
public:
	MonkGroup::MonkGroup();
	MonkGroup(sf::Vector2f position, int NumberOfMonks, float fRadius);							//Constructor

	void setRadius(float radius);
	void setMonkCount(int Num);
	void setPosition(sf::Vector2f pos);
	void update(sf::Time h);
	
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
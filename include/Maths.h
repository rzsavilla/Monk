#ifndef MATHS_H
#define MATHS_H

#include <SFML/Graphics.hpp>

namespace Maths
{
	const float PI = 3.14159;
	const float RadToDeg = 180 / PI;
	const float DegToRad = PI / 180;

	float Magnitude(sf::Vector2f vector)
	{
		return sqrt((vector.x * vector.x) + (vector.y * vector.y));
	}
};

#endif
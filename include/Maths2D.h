#ifndef MATHS2D_H
#define MATHS2D_H

#include <SFML/Graphics.hpp>
#include <SFML\System\Vector2.hpp>

namespace Maths2D
{
	const float PI = 3.14159;
	const float RadToDeg = 180 / PI;
	const float DegToRad = PI / 180;

	template <class T>
	float Magnitude(sf::Vector2<T> vector)
	{
		return sqrt((vector.x * vector.x) + (vector.y * vector.y));
	}
};

#endif
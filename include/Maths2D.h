#ifndef MATHS2D_H
#define MATHS2D_H

#include <SFML/Graphics.hpp>
#include <SFML\System\Vector2.hpp>

namespace Maths2D
{
	const float PI = 3.14159;

	template <class T>
	float Magnitude(sf::Vector2<T> vector)
	{
		return sqrt((vector.x * vector.x) + (vector.y * vector.y));
	}

	template <class T>
	sf::Vector2<T> UnitVector(sf::Vector2<T>& vector)
	{
		const float kfMagnitude = Maths2D::Magnitude(vector);
		return vector / kfMagnitude;
	}

	template <class T>
	T RadToDeg(float radians)
	{
		return radians * 180 / PI;
	}

	template <class T>
	T DegToRad(float degrees)
	{
		return degrees * PI / 180;
	}
};

#endif
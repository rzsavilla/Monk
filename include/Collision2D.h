#ifndef COLLISION2D_H
#define COLLISION2D_H

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\System\Vector2.hpp>

class Maths;

class Collision2D
{
public:
	static bool HaveCollided_Circle(const sf::Sprite& sprite1, const sf::Sprite& sprite2);
private:
	static float GetRadius(const sf::Sprite& sprite);
	static sf::Vector2f GetCenter(const sf::Sprite& sprite);
	static sf::Vector2f GetSize(const sf::Sprite& sprite);
};

#endif
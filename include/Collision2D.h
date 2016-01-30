#ifndef COLLISION2D_H
#define COLLISION2D_H

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\System\Vector2.hpp>

class Maths;

struct CollisionInfo 
{
	const bool collided;
	const float magnitude;
	CollisionInfo(bool collide, float mag) : collided(collide), magnitude(mag) {}
};

class Collision2D
{
public:
	static CollisionInfo HaveCollided_Circle(const sf::Sprite& sprite1, const sf::Sprite& sprite2);
	static bool IsWithinRadius(const sf::Sprite& sprite1, const sf::Sprite& sprite2, const float radius1);
private:
	static float GetRadius(const sf::Sprite& sprite);
	static sf::Vector2f GetCenter(const sf::Sprite& sprite);
	static sf::Vector2f GetSize(const sf::Sprite& sprite);
};

#endif
#include "Collision2D.h"
#include "Maths.h"

bool Collision2D::HaveCollided_Circle(const sf::Sprite& sprite1, const sf::Sprite& sprite2)
{
	// Check for a collision between the two circles
	const sf::Vector2f kfCenterSubtraction = GetCenter(sprite1) - GetCenter(sprite2);
	const float kfMagnitude = Maths::Magnitude(kfCenterSubtraction);
	const float kfRadiiSum = GetRadius(sprite1) + GetRadius(sprite2);
	return kfMagnitude < kfRadiiSum;
}

float Collision2D::GetRadius(const sf::Sprite& sprite)
{
	// Calculate the radius of the sprite
	const sf::Vector2f kfSpriteSize = GetSize(kSprite);
	return (kfSpriteSize.x + kfSpriteSize.y) / 4;
}

sf::Vector2f Collision2D::GetCenter(const sf::Sprite& sprite)
{
	sf::FloatRect AABB = sprite.getGlobalBounds();
	return sf::Vector2f(AABB.left + AABB.width / 2.f, AABB.top + AABB.height / 2.f);
}

sf::Vector2f Collision2D::GetSize(const sf::Sprite& sprite)
{
	// Return the size of the sprite adjusting for scale
	const sf::IntRect iOriginalSize = sprite.getTextureRect();
	const sf::Vector2f fScale = sprite.getScale();
	return sf::Vector2f(iOriginalSize.width * fScale.x, iOriginalSize.height * fScale.y);
}
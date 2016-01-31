#ifndef END_SCREEN_H
#define END_SCREEN_H

#include "InputHandler.h"

class End_Screen : public sf::Drawable
{
private:
	sf::Font font;
	sf::Text scoreText;
	sf::Sprite background;
	sf::Texture bg;
	sf::Texture end;
	sf::Sprite End_Button;
public:
	End_Screen();
	void GetWindow(sf::Vector2u windowSize);
	int update(InputHandler& input, int& score);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
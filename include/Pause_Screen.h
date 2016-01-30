#ifndef PAUSE_SCREEN_H
#define PAUSE_SCREEN_H

#include "InputHandler.h"

class Pause_Screen : public sf::Drawable
{
private:
	sf::Sprite background;
	sf::Texture bg;
	sf::RectangleShape Pause_Button;
public:
	Pause_Screen();
	void GetWindow(sf::Vector2u windowSize);
	int update(InputHandler& input);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
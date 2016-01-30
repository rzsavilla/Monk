#ifndef START_SCREEN_H
#define START_SCREEN_H

#include "InputHandler.h"

class Start_Screen:  public sf::Drawable  
{
private:
	sf::Sprite background;
	sf::Texture bg;
	sf::RectangleShape Start_Button;
public:
	Start_Screen();
	void GetWindow(sf::Vector2u windowSize);
	int update(InputHandler& input);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
#ifndef START_SCREEN_H
#define START_SCREEN_H

#include "InputHandler.h"

class Start_Screen:  public sf::Drawable  
{
public:
	Start_Screen();
	int update(InputHandler& input);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::RectangleShape Start_Button;
};

#endif
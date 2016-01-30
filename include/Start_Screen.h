#ifndef START_SCREEN_H
#define START_SCREEN_H

#include "Game.h"
#include "InputHandler.h"

class Start_Screen:  public sf::Drawable  
{
public:
	Start_Screen();
	void update(InputHandler& input);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	
};

#endif
#ifndef END_SCREEN_H
#define END_SCREEN_H

#include "InputHandler.h"

class End_Screen : public sf::Drawable
{
private:
	sf::Sprite background;
	sf::Texture bg;
	sf::Texture end;
	sf::Sprite End_Button;
public:
	End_Screen();
	void GetWindow(sf::Vector2u windowSize);
	int update(InputHandler& input);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
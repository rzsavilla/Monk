#ifndef HOW_SCREEN_H
#define HOW_SCREEN_H

#include "InputHandler.h"

class How_Screen : public sf::Drawable
{
private:
	sf::Sprite background;
	sf::Texture bg;
	sf::Texture next;
	sf::Sprite Next_Button;
public:
	How_Screen();
	void GetWindow(sf::Vector2u windowSize);
	int update(InputHandler& input);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
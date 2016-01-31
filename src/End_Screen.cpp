#include "End_Screen.h"

End_Screen::End_Screen()
{
	bg.loadFromFile("assets\\screens\\end_background.png");
	background.setTexture(bg);

	end.loadFromFile("assets\\sprites\\end_button.png");
	End_Button.setTexture(end);
	End_Button.setOrigin(sf::Vector2f(end.getSize().x / 2, end.getSize().y / 2));

	font.loadFromFile("assets/fonts/times.ttf");
	scoreText.setFont(font);
	scoreText.setPosition(580, 440);
}

void End_Screen::GetWindow(sf::Vector2u windowSize)
{
	End_Button.setPosition(sf::Vector2f(windowSize.x / 2, windowSize.y * 3 / 4));
}

int End_Screen::update(InputHandler& input, int& score)
{
	int  iNewState = 3;

	if (input.bLeftClick) {
		if (input.mousePos.x > End_Button.getPosition().x - (end.getSize().x / 2) && input.mousePos.x < End_Button.getPosition().x + (end.getSize().x / 2))
		{
			if (input.mousePos.y > End_Button.getPosition().y - (end.getSize().y / 2) && input.mousePos.y < End_Button.getPosition().y + (end.getSize().y / 2))
			{
				iNewState = 0;
				input.bLeftClick = false;
			}
		}
	}

	scoreText.setString("Score: " + std::to_string(score));
	return iNewState;
}

void End_Screen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(background, states);
	target.draw(End_Button, states);
	target.draw(scoreText);
}
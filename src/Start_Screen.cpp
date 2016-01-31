#include "Start_Screen.h"

Start_Screen::Start_Screen()
{
	bg.loadFromFile("assets\\screens\\start_background.png");
	background.setTexture(bg);

	start.loadFromFile("assets\\sprites\\start_button.png");
	Start_Button.setTexture(start);
	Start_Button.setOrigin(sf::Vector2f(start.getSize().x / 2, start.getSize().y / 2));
}

void Start_Screen::GetWindow(sf::Vector2u windowSize) 
{
	Start_Button.setPosition(sf::Vector2f(windowSize.x / 2, windowSize.y * 7 / 8));
}

int Start_Screen::update(InputHandler& input)
{
	int  iNewState = 0;

	if (input.bLeftClick) {
		if (input.mousePos.x > Start_Button.getPosition().x - (start.getSize().x / 2) || input.mousePos.x < Start_Button.getPosition().x + (start.getSize().x / 2))
		{
			if (input.mousePos.y > Start_Button.getPosition().y - (start.getSize().y / 2) || input.mousePos.y < Start_Button.getPosition().y + (start.getSize().y / 2))
			{
				iNewState = 4;
				input.bLeftClick = false;
			}
		}
	}

	return iNewState;
}

void Start_Screen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(background, states);
	target.draw(Start_Button, states);
}
//void Start_Screen::update(InputHandler& input)
//{
//	// Check for events
//	if (input.bLeftClick)
//	{
//		sf::RectangleShape mouseArea = sf::RectangleShape(sf::Vector2f(10, 10));
//		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
//		mouseArea.setPosition(mousePosition.x, mousePosition.y);
//		if (startButton.getGlobalBounds().intersects(mouseArea.getGlobalBounds()))
//			// Start game
//			gameState = RUNNING;
//	}
//}
//
//void Start_Screen::run()
//{
//	// Change the background colour
//	m_pGame->window.clear(sf::Color::Blue);
//	// Create buttons
//	sf::RectangleShape startButton;
//	startButton.setSize(sf::Vector2f(256, 72));
//	startButton.setPosition(sf::Vector2f(512, 500));
//	startButton.setFillColor(sf::Color::Green);
//	// Draw the button
//	window.draw(startButton);
//	// Update the window
//	window.display();
//
//
//}
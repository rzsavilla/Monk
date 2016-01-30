#include "Start_Screen.h"

Start_Screen::Start_Screen() {}

void Start_Screen::update(InputHandler& input)
{

}

void Start_Screen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

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
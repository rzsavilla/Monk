#include "Game.h"

#include <iostream>

Game::Game() : window(sf::VideoMode(1280,640), "Monk", sf::Style::Titlebar|sf::Style::Close)
{
	iState = 0;
}

void Game::run()
{
	while (window.isOpen()) 
	{
		handleEvents();
		update();
		render();
	}
}

void Game::handleEvents() 
{
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (event.type == sf::Event::KeyPressed) {
			input.updateKeyPress(event.key.code, true);
		}
		if (event.type == sf::Event::KeyReleased) {
			input.updateKeyPress(event.key.code, false);
		}
		if (event.type == sf::Event::MouseButtonPressed) {
			input.updateMousePress(event.mouseButton.button, true);
		}
		else if (event.type == sf::Event::MouseButtonReleased) {
			//input.updateMousePress(event.mouseButton.button, false);
		}
		if (event.type == sf::Event::MouseMoved) {
			input.updateMousePos(sf::Mouse::getPosition(window));				//!< \param takes mouse position relative to window
		}
	}
}

void Game::update() 
{
	if (iState == 0) {						//!< Start Screen
		iState = start_screen.update(input);
	}
	else if (iState == 1) {					//!< Game Screen

	}
	else if (iState == 2) {					//!< Pause Screen

	}
	else if (iState == 3) {					//!< End Screen

	}
}

void Game::render() 
{
	window.clear();

	if (iState == 0) {						//!< Start Screen
		window.draw(start_screen);
	}
	else if (iState == 1) {					//!< Game Screen

	}
	else if (iState == 2) {					//!< Pause Screen

	}
	else if (iState == 3) {					//!< End Screen

	}

	window.display();
}
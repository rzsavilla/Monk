#include "Game.h"

#include <iostream>

Game::Game() : window(sf::VideoMode(1280, 720), "Monk", sf::Style::Titlebar | sf::Style::Close)
{
	start_screen.GetWindow(window.getSize());
	pause_screen.GetWindow(window.getSize());
	end_screen.GetWindow(window.getSize());
	iState = 0;
}

void Game::run()
{
	while (window.isOpen()) 
	{
		handleEvents();
		update(timer.restart());
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

void Game::update(sf::Time h) 
{
	if (iState == 0) {						//!< Start Screen
		iState = start_screen.update(input);
	}
	else if (iState == 1) {					//!< Game Screen
		iState = play_screen.update(h,input);
	}
	else if (iState == 2) {					//!< Pause Screen
		iState = pause_screen.update(input);
	}
	else if (iState == 3) {					//!< End Screen
		iState = end_screen.update(input);
	}
}

void Game::render() 
{
	window.clear();

	if (iState == 0) {						//!< Start Screen
		window.draw(start_screen);
	}
	else if (iState == 1) {					//!< Game Screen
		window.draw(play_screen);
	}
	else if (iState == 2) {					//!< Pause Screen
		window.draw(pause_screen);
	}
	else if (iState == 3) {					//!< End Screen
		window.draw(end_screen);
	}

	window.display();
}
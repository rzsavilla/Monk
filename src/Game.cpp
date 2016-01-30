#include "Game.h"

Game::Game() : window(sf::VideoMode(1280,640), "Monk", sf::Style::Titlebar|sf::Style::Close) {

}

void Game::run()
{
	while (window.isOpen()) {
		handleEvents();
		update();
		render();
	}
}

void Game::handleEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (event.type == sf::Event::KeyPressed) {
			input.updateKeyPress(event.key.code, true);
		}
		if (event.type == sf::Event::KeyPressed) {
			input.updateKeyPress(event.key.code, false);
		}
		if (event.type == sf::Event::MouseButtonPressed) {
			input.updateMousePress(event.mouseButton.button, true);
		}
		if (event.type == sf::Event::MouseButtonReleased) {
			input.updateMousePress(event.mouseButton.button, false);
		}
		if (event.type == sf::Event::MouseMoved) {
			input.updateMousePos(sf::Mouse::getPosition(window));				//!< \param takes mouse position relative to window
		}
	}
}

void Game::update() {

}
void Game::render() {
	window.clear();

	window.display();
}
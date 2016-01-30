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
	}
}
void Game::update() {

}
void Game::render() {
	window.clear();

	window.display();
}
#include "Play_Screen.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Play_Screen::Play_Screen() {
	bg.loadFromFile("assets\\screens\\game_background.png");
	background.setTexture(bg);

	texture.loadFromFile("assets/sprites/enemy.png");

	monk.setTexture(texture);
	monk.setPosition(640, 320);
	monk.setSpeed(100.f);
	monk.setMaxSpeed(100.f);
	monk.setRadius(monk.getGlobalBounds().width / 2);
	monk.setOrigin(monk.getGlobalBounds().width / 2, monk.getGlobalBounds().width / 2);

	enemy.setTexture(texture);
	enemy.setPosition(640, 500);
	enemy.setSpeed(100.f);
	enemy.setMaxSpeed(100.f);
	enemy.setRadius(50.f);

	monk_Group.setMonkCount(10);

	spawner.setPoints(20);
	spawner.setRadius(720);
	spawner.setSpawn(monk);
		
	spawner.setPosition(sf::Vector2f(640, 360));
	spawner.spawn();

	font.loadFromFile("assets/fonts/times.ttf");
	scoreText.setFont(font);
	scoreText.setPosition(20, 10);
}

int Play_Screen::update(sf::Time h,InputHandler& input, int& iScore) {
	int iNewState = 1;

	//Check button presses
	if (input.bEsc) {
		iNewState = 2;
		input.bEsc = false;
	}

	//if gameover, change to end screen, 3
	//iNewState = 3;

	//REMOVE the input check here, once proper game over check is made
	if (input.bRight) {
		iNewState = 3;
	}

	monk_Group.updateMoveT();
	spawner.updateMoveTo();
	//Set/Changes velocity
	monk_Group.selfCollide();
	
	spawner.selfCollide();
	spawner.collideMonks(monk_Group.Monks);

	// Update score
	scoreText.setString("Score: " + std::to_string(iScore));

	//Move using velocity
	spawner.update(h,input,iScore);
	monk_Group.update(h);
	return iNewState;
}

void Play_Screen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(background);
	target.draw(monk_Group, states);
	target.draw(spawner, states);
	target.draw(scoreText);
	//target.draw(monk, states);
	//target.draw(enemy, states);
	
}
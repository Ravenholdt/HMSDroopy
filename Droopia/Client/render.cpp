
#ifndef RENDER_CPP
#define RENDER_CPP

#include "global.h"

#include "render.hpp"

#include "textures.hpp"


int tileSize = 80;

//int map[15][11];

float moveX, moveY;

void mainWindow() {
	LoadTextures();
	sf::RenderWindow window(sf::VideoMode(1300, 900), "Droopia");
	window.setVerticalSyncEnabled(true);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		//MoveCharacter();

		for (int cordX = 0; cordX < 15; cordX++) {
			for (int cordY = 0; cordY < 11; cordY++) {
				grassSprite.setPosition(cordX * 80 - 40, cordY * 80 - 40);
				window.draw(grassSprite);
				if (cordX == 3 && cordY == 5) {
					rockSprite.setPosition(cordX * 80 - 40, cordY * 80 - 40);
					window.draw(rockSprite);
				}
			}
		}

		window.draw(playerSprite);
		window.display();
	}
}

void MoveCharacter(int direction, float speed) {
	int playerTextureOffset = 128;

	sf::Vector2f movement = sf::Vector2f(0, 0);

	if (direction == 0) { //Up
		movement = sf::Vector2f(0, -1.f);
	}
	else if (direction == 1) { //Left
		movement = sf::Vector2f(-1.f, 0);
	}
	else if (direction == 2) { //Right
		movement = sf::Vector2f(1.f, 0);
	}
	else if (direction == 3) { //Down
		movement = sf::Vector2f(0, 1.f);
	}
	else {
		movement = sf::Vector2f(0, 0);
	}

	movement *= speed;

	playerSprite.setTextureRect(sf::IntRect(0,
		direction * playerTextureOffset, playerTextureOffset, playerTextureOffset));

	if (speed < 1) {
		for (float i = 0; i < tileSize; i += speed) {
			Sleep(1);
			playerSprite.move(movement);
		}
	}
}
	
/*void MoveCharacter() {

	int playerTextureOffset = 128;
	playerSprite.move(moveX, moveY);

	if (moveX > 0) { //Right
		playerSprite.setTextureRect(sf::IntRect(0,
			2 * playerTextureOffset, playerTextureOffset, playerTextureOffset));
	}
	else if (moveX < 0) { //Left
		playerSprite.setTextureRect(sf::IntRect(0,
			1 * playerTextureOffset, playerTextureOffset, playerTextureOffset));
	}
	else if (moveY < 0) { //Up
		playerSprite.setTextureRect(sf::IntRect(0,
			0 * playerTextureOffset, playerTextureOffset, playerTextureOffset));
	}
	else if (moveY > 0) { //Down
		playerSprite.setTextureRect(sf::IntRect(0,
			3 * playerTextureOffset, playerTextureOffset, playerTextureOffset));
	}

	moveX = 0;
	moveY = 0;
}*/

#endif
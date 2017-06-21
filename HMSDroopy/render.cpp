

#include "global.h"

#include "render.hpp"

#include "textures.hpp"


int tileSize = 80;

//int map[15][11];

float moveX, moveY;

void mainWindow() {
	LoadTextures();
	sf::RenderWindow window(sf::VideoMode(604, 604), "HMS Droopy");
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


		window.draw(spriteRadar);
		spriteRadarCursor.rotate(1);
		window.draw(spriteRadarCursor);
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
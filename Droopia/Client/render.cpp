
#ifndef RENDER_CPP
#define RENDER_CPP

#include "global.h"

#include "render.hpp"


sf::Sprite playerSprite;
sf::Texture playerTexture;

float moveX, moveY;

void mainWindow() {
	LoadTextures();
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Droopia");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		MoveCharacter();

		window.draw(playerSprite);
		window.display();
	}
}

void LoadTextures() {
	playerTexture.loadFromFile("Client/textures/player.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setTextureRect(sf::IntRect(0, 0, 128, 128));
}

void MoveCharacter() {
	int playerTextureOffset = 128;
	playerSprite.move(moveX, moveY);

	if (moveX > 0) //Right
		playerSprite.setTextureRect(sf::IntRect(0,
			2 * playerTextureOffset, playerTextureOffset, playerTextureOffset));
	else if (moveX < 0) //Left
		playerSprite.setTextureRect(sf::IntRect(0,
			1 * playerTextureOffset, playerTextureOffset, playerTextureOffset));
	else if (moveY < 0) //Up
		playerSprite.setTextureRect(sf::IntRect(0,
			0 * playerTextureOffset, playerTextureOffset, playerTextureOffset));
	else if (moveY > 0) //Down
		playerSprite.setTextureRect(sf::IntRect(0,
			3 * playerTextureOffset, playerTextureOffset, playerTextureOffset));

	moveX = 0;
	moveY = 0;
}

#endif
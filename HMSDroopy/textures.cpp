#include "textures.hpp"

sf::Sprite playerSprite;
sf::Texture playerTexture;

sf::Sprite grassSprite;
sf::Texture groundTexture;

sf::Sprite rockSprite;
sf::Texture enviromentTexture;

void LoadTextures() {
	playerTexture.loadFromFile("Client/textures/player.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setTextureRect(sf::IntRect(0, 0, 128, 128));

	groundTexture.loadFromFile("Client/textures/ground.png");
	grassSprite.setTexture(groundTexture);

	enviromentTexture.loadFromFile("Client/textures/enviroment.png");
	rockSprite.setTexture(enviromentTexture);
}

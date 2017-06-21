#ifndef TEXTURES_H
#define TEXTURES_H

#include "sfml.hpp"

extern sf::Sprite playerSprite;
extern sf::Texture playerTexture;

extern sf::Sprite grassSprite;
extern sf::Texture groundTexture;

extern sf::Sprite rockSprite;
extern sf::Texture enviromentTexture;

extern sf::Sprite spriteRadar;
extern sf::Texture textureRadar;

extern sf::Sprite spriteRadarCursor;
extern sf::Texture textureRadarCursor;

void LoadTextures();


#endif // !TEXTURES_H

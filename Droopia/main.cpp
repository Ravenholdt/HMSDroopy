
#include <iostream>
#include <thread>

#include "global.h"

#include "main.hpp"

int main()
{
	moveX = 0;
	moveY = 0;
	std::thread mainWindowThread(mainWindow);
	std::thread keyboardThread(keyboard);
	mainWindowThread.join();

	return 0;
}

float movspeed = 0.1f;

void keyboard() {
	while (true) {

		Sleep(5);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

			//Left key is pressed
			moveX--;
			std::cout << "Left, ";
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

			//Up key is pressed
			moveY--;
			std::cout << "Up, ";
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

			//Right key is pressed
			moveX++;
			std::cout << "Right, ";
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

			//Down key is pressed
			moveY++;
			std::cout << "Down, ";
		}
	}

}
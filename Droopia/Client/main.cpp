
#include <iostream>
#include <thread>

#include "global.h"

#include "main.hpp"

int main()
{
	moveX = 0;
	moveY = 0;
	std::thread mainWindowThread(mainWindow);
	std::thread keyboardThread(MovementKeyboard);
	mainWindowThread.join();

	return 0;
}

float movspeed = 0.1f;

void MovementKeyboard() {
	float speed = 0.1f;
	while (true) {

		Sleep(5);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

			//Up key is pressed
			std::cout << "Up, ";
			MoveCharacter(0, speed);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

			//Left key is pressed
			std::cout << "Left, ";
			MoveCharacter(1, speed);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

			//Right key is pressed
			std::cout << "Right, ";
			MoveCharacter(2, speed);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

			//Down key is pressed
			std::cout << "Down, ";
			MoveCharacter(3, speed);
		}

		/*Sleep(5);

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
		}*/
	}

}
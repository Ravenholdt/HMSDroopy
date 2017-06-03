using namespace std;

#include <iostream>
#include <thread>

//Include SFML
#include <SFML\Audio.hpp>
#include <SFML\Config.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Main.hpp>
#include <SFML\Network.hpp>
#include <SFML\OpenGL.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>

void keyboard(sf::CircleShape shape) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

		//Left key is pressed
		shape.move(-10, 0);
		cout << "Left";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

		//Up key is pressed
		shape.move(0, -10);
		cout << "Up";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

		//Right key is pressed
		shape.move(10, 0);
		cout << "Right";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

		//Down key is pressed
		shape.move(0, 1);
		cout << "Down";
	}

}

void mainWindow() {
	sf::RenderWindow window(sf::VideoMode(200, 200), "Droopia");
	sf::CircleShape shape(10.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();

		keyboard(shape);
	}
}

int main()
{
	std::thread t1(mainWindow);
	t1.join();

	return 0;
}


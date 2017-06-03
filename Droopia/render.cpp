//Include SFML
#include <SFML\Audio.hpp>
#include <SFML\Config.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Main.hpp>
#include <SFML\Network.hpp>
#include <SFML\OpenGL.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>

/*void mainWindow() {
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
}*/
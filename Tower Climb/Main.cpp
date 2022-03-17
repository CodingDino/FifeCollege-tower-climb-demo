#include <SFML/Graphics.hpp>
#include "Player.h"

int main()
{

	sf::RenderWindow window(sf::VideoMode(700, 700), "SFML Works!");

	sf::Clock gameClock;

	Player myPlayer;

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Update
		sf::Time frameTime = gameClock.restart();
		myPlayer.Update(frameTime);

		// Draw
		window.clear();

		myPlayer.Draw(window);

		window.display();

	}


	return 0;
}
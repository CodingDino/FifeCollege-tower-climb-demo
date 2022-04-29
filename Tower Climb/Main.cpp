#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Platform.h"

int main()
{

	sf::RenderWindow window(sf::VideoMode(700, 700), "SFML Works!");

	sf::Clock gameClock;

	Player myPlayer;

	Platform myPlatform;
	myPlatform.SetPosition(sf::Vector2f(0, 400));

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

		// Check collision
		myPlatform.HandleCollision(myPlayer);

		// Draw
		window.clear();

		myPlayer.Draw(window);

		myPlatform.Draw(window);

		window.display();

	}


	return 0;
}
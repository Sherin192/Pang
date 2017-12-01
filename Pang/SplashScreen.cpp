#include "SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow &window)
{
	sf::Texture splashScreenImg;
	splashScreenImg.loadFromFile("images/Splashscreen.png");
	/*if (splashScreenImg.loadFromFile("Splashscreen.png") == false);
	{
		return;
	}*/
	sf::Sprite sprite(splashScreenImg);
	
	
	window.draw(sprite);
	window.display();

	sf::Event event;
	while (true)
	{
		while (window.pollEvent(event))

			if (event.type == sf::Event::EventType::KeyPressed || event.type == sf::Event::EventType::MouseButtonPressed || event.type == sf::Event::EventType::Closed)
			{
				return;
			}
	}
}
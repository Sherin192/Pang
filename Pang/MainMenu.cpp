#include "MainMenu.h"
#include <iostream>
MainMenu::MenuResult MainMenu::Show(sf::RenderWindow &window)
{	

	
	menu.loadFromFile("images/Mainmenu2.png");
	sprite.setTexture(menu);
	MenuItem playButton;
	playButton.rect.top = 500;
	playButton.rect.height = 75;
	playButton.rect.left = 20;
	playButton.rect.width = 200;
	playButton.action = Play;

	MenuItem exitButton;
	exitButton.rect.top = 575;
	exitButton.rect.height = 75;
	exitButton.rect.left = 20;
	exitButton.rect.width = 200;
	exitButton.action = Exit;
	
	menuItem.push_back(playButton);
	menuItem.push_back(exitButton);
	isBlackHole.setPosition(185, 675);
	//window.clear(sf::Color::Black);
	
	std::cout << "DISPLAY " << std::endl;
	return GetMenuResponse(window);
}
MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;
	isBlackHole.update(isBlackHole.hit(sf::Vector2i(x, y), isBlackHole.getBoundingRect()));
	for (it = menuItem.begin(); it != menuItem.end(); ++it)
	{
		sf::Rect<int> menuItemRect = it->rect;

		if (menuItemRect.top + menuItemRect.height > y &&
			menuItemRect.top < y &&
			menuItemRect.left < x &&
			menuItemRect.width > x)
		{
			return it->action;
		}
	}
	return Nothing;
}
MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow &window)
{
	sf::Event event;
	MenuResult result = Nothing;
	while (true)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::MouseButtonPressed)
			{
				result = HandleClick(event.mouseButton.x, event.mouseButton.y);
			}
			if (event.type == sf::Event::EventType::Closed)
			{
				result = Exit;
			}
			if (result != Nothing)
				return result;
			window.clear(sf::Color::Black);
			window.draw(sprite);
			isBlackHole.draw(window);
			window.display();
		}
		
	}
}

bool MainMenu::isBH()
{
	return isBlackHole.isOn;
}
#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "CheckBox.h"
#include <list>
class MainMenu
{
	

	
public:
	enum MenuResult { Nothing, Exit, Play };
	MenuResult Show(sf::RenderWindow &window);
	bool isBH();
private:
	sf::Texture menu;
	sf::Sprite sprite;
	CheckBox isBlackHole;
	MenuResult GetMenuResponse(sf::RenderWindow &window);
	MenuResult HandleClick(int x, int y);
	
	struct MenuItem
	{
		sf::Rect<int> rect;
		MenuResult action;
	};
	std::list<MenuItem> menuItem;
};
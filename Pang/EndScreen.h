#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Globals.h"
class EndScreen
{
	sf::Texture texture;
	sf::RectangleShape replay;
	sf::Sprite endGame;
public:
	
	EndScreen(std::string name);
	void Show(sf::RenderWindow &window);
	bool EndScreen::hit(sf::Vector2i mousePosition);
};
#include "EndScreen.h"
EndScreen::EndScreen(std::string name)
{
	texture.loadFromFile(name);
	replay.setSize(sf::Vector2f(435, 30));
	endGame.setTexture(texture);
}
void EndScreen::Show(sf::RenderWindow &window)
{
	
	replay.setPosition(285, 320);
	window.draw(endGame);
	window.display();
}
bool EndScreen::hit(sf::Vector2i mousePosition)
{
		
	if (mousePosition.x > replay.getGlobalBounds().left
		&& mousePosition.x < replay.getGlobalBounds().left + replay.getGlobalBounds().width
		&& mousePosition.y > replay.getGlobalBounds().top
		&& mousePosition.y < replay.getGlobalBounds().top + replay.getGlobalBounds().height)
	{
		//		if the mouse position is inside the rectangle 	
		return true;
	}
	else
	{
		return false;
	}
}
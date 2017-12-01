#include "EndScreen.h"
EndScreen::EndScreen(std::string name)
{
	texture.loadFromFile(name);
	replay.setSize(sf::Vector2f(435, 30));
	//replay.setOrigin(120, 15);
	endGame.setTexture(texture);
}
void EndScreen::Show(sf::RenderWindow &window)
{
	
	//endGame.setOrigin(endGame.getLocalBounds().width / 2, endGame.getLocalBounds().height / 2);
	//endGame.setPosition(WIDTH / 2, HEIGHT / 2);
	replay.setPosition(285, 320);
	//replay.setFillColor(sf::Color::Black);
	//window.clear(sf::Color::White);
	window.draw(endGame);
	//window.draw(replay);
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
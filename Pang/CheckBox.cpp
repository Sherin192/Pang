#pragma once
#include "CheckBox.h"

CheckBox::CheckBox()
{
	load("images/checkbox.png");
	getSprite().setTextureRect(sf::IntRect(0, 0, 33, 34));
	getSprite().setOrigin(sf::Vector2f(16, 17));
	isOn = false;
}

void CheckBox::update(bool hit)
{
	std::cout << hit << std::endl;
	std::cout << isOn << std::endl;
	if (hit)
	{
		if (isOn)
		{
			getSprite().setTextureRect(sf::IntRect(33, 0, 37, 34));
		}
		else
		{
			getSprite().setTextureRect(sf::IntRect(0, 0, 33, 34));
		}
	}

}
bool CheckBox::hit(sf::Vector2i mousePosition, sf::FloatRect rectangle)
{

	if (mousePosition.x > rectangle.left
		&& mousePosition.x < rectangle.left + rectangle.width
		&& mousePosition.y > rectangle.top
		&& mousePosition.y < rectangle.top + rectangle.height)
	{
		//		if the mouse position is inside the rectangle 	
		isOn = !isOn;
		return true;
	}
	else
	{
		return false;
	}
}





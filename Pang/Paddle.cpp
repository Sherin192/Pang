#include "Paddle.h"
#include <cassert>
#include <iostream>
Paddle::Paddle(): velocity(0), maxVelocity(200.0f)
{
	load("images/paddle.png");
	assert(isLoaded());
	getSprite().setOrigin(15,45);
}

void Paddle::draw(sf::RenderWindow &window)
{
	GameObject::draw(window);
}
float Paddle::getVelocity() const
{
	return velocity;
}
void Paddle::update(float elapsedTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		velocity = -maxVelocity;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		velocity = maxVelocity;
	}
	else 
	{
		velocity = 0;
	}

	sf::Vector2f pos = this->getPosition();
	
	if (pos.y <= 45)
	{
		pos.y = 46;
		velocity = maxVelocity;
	}
	else if (pos.y >= (HEIGHT - 45))
	{
		pos.y = HEIGHT - 46;
		velocity = -maxVelocity;
	}

	getSprite().move(0, velocity * elapsedTime);
}


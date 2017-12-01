#include "PaddleAI.h"
#include <cassert>
#include <iostream>
PaddleAI::PaddleAI() : velocity(0), maxVelocity(200.0f), minVelocity(50.0f)
{
	load("images/paddle.png");
	assert(isLoaded());
	getSprite().setOrigin(15, 45);

}
PaddleAI::~PaddleAI()
{

}
void PaddleAI::draw(sf::RenderWindow &window)
{
	GameObject::draw(window);
}
float PaddleAI::getVelocity() const
{
	return velocity;
}
void PaddleAI::update(float elapsedTime)
{
	Ball* ball = dynamic_cast<Ball*>(Game::getGameObjectManager().get("ball"));
	
	if (ball->getAngle() > 250 && ball->getAngle() < 280 && ball->getPosition().x > 250)
	{
		if (getPosition().y < HEIGHT / 2 - 10)
			velocity += 10;
		else if (getPosition().y > HEIGHT / 2 + 10)
			velocity -= 10;
		else
			velocity = 0;
	}

	if (getPosition().y - 20 < ball->getPosition().y)
	{
		velocity += 15;
		//if (ball->getAngle() > 200 && ball->getAngle() > 260 && ball->getPosition().x < 300)
			//velocity = 0;
			
	}
	else if (getPosition().y + 20 > ball->getPosition().y)
	{
		velocity -= 15;
		//if (ball->getAngle() < 180 && ball->getAngle() > 90 && ball->getPosition().x < 300)
			//velocity = 0;
	}
	else
		velocity = 0;
	if (ball->getPosition().x > 500)
	{
		if (getPosition().y < HEIGHT / 2 - 10)
			velocity += 10;
		else if (getPosition().y > HEIGHT / 2 + 10)
			velocity -= 10;
		else
			velocity = 0;
	}

	if (velocity > maxVelocity)
		velocity = maxVelocity;
	if (velocity < -maxVelocity)
		velocity = -maxVelocity;
	sf::Vector2f pos = this->getPosition();

	if (pos.y <= 45)
	{
		pos.y = 46;	
		velocity = 50;
	}
	else if (pos.y >= (HEIGHT - 45))
	{
		pos.y = HEIGHT - 46;
		velocity = - 50;
	}
	//if (elapsedTime >= 1.0f)
	//velocity = 0;
	getSprite().move(0, velocity * elapsedTime);
}

#include "CountDown.h"

CountDown::CountDown()
{
	load("images/CountDownSprite.png");
	getSprite().setTextureRect(sf::IntRect(3 * 64, 0, 64, 64));
	getSprite().setOrigin(32, 32);
}
CountDown::~CountDown()
{

}
void CountDown::update(float elapsedTime)
{
	this->elapsedTime += elapsedTime;
	if (this->elapsedTime < 1.0f)
		return;
	
	if (this->elapsedTime >= 1.0f && this->elapsedTime < 2.0f)
		getSprite().setTextureRect(sf::IntRect(2 * 64, 0, 64, 64));
	else if(this->elapsedTime >= 2.0f && this->elapsedTime < 3.0f)
		getSprite().setTextureRect(sf::IntRect(1 * 64, 0, 64, 64));
	else if(this->elapsedTime >= 3.0f && this->elapsedTime <= 4.0f)
		getSprite().setTextureRect(sf::IntRect(0 * 64, 0, 64, 64)); 
}

float CountDown::elapsedTime = 0.0f;
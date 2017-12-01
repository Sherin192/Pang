#pragma once
#include "GameObject.h"
#include "Paddle.h"

class Ball : public GameObject
{
public:
	float velocity;
	float maxVelocity;

	Ball();
	virtual ~Ball();

	void update(float elapsedtime);
	float getAngle() { return angle;}

private:
	float moveX;
	float moveY;
	bool hit = false;
	bool increase = false;
	float angle;
	float minVelocity;
	float elapsedTimeSinceStart;
	//sound related variables only the ball has a sound effect so this is not implemented in the base class
	sf::SoundBuffer buffer;
	sf::SoundBuffer losebuffer;
	sf::Sound sound;
	sf::Sound losepoint;

	float linearVelocityX(float angle);
	float linearVelocityY(float angele);
	bool colliision(sf::FloatRect bb1, sf::FloatRect bb2, sf::Vector2f pos1, sf::Vector2f pos2);
};
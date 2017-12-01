#pragma once

#include "GameObject.h"
#include "Game.h"
#include "ball.h"
#include "ScoreBoard.h"

class Paddle : public GameObject
{
	float velocity;
	const float maxVelocity;
public:
	
	int score;
	Paddle();
	~Paddle();
	void update(float elapsedTime);
	void draw(sf::RenderWindow &wnindow);
	float getVelocity() const;

	
};
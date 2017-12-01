#pragma once

#include "GameObject.h"
#include "Game.h"
#include "ball.h"
#include "ScoreBoard.h"
//class ScoreBoard;
class PaddleAI : public GameObject
{
	//sf::RenderWindow *window;
	//sf::RectangleShape paddle;
public:

	int score;
	PaddleAI();
	~PaddleAI();
	void update(float elapsedTime);
	void draw(sf::RenderWindow &wnindow);
	float getVelocity() const;
private:
	float velocity;
	float maxVelocity;
	float minVelocity;
};
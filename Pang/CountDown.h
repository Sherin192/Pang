#pragma once
#include "GameObject.h"
#include "ball.h"
class CountDown :public GameObject
{
	
public:
	static float elapsedTime;
	CountDown();
	void update(float elapsedTime);
	
};

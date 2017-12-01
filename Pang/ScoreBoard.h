#pragma once
#include "Game.h"
#include "GameObject.h"
class ScoreBoard :public GameObject
{
public:
	std::string ID;
	ScoreBoard(std::string ID);

	void update(float score);
};
#pragma once
#include "GameObject.h"
class CheckBox : public GameObject
{
	bool hitbox;
public:
	CheckBox();
	~CheckBox();
	//bool isCheck();
	bool isOn;
	void update(bool hit);
	bool hit(sf::Vector2i mousePosition, sf::FloatRect rectangle);

};
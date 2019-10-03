#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Globals.h"
#include <iostream>
//---------------------------------------------------------------------------------------------------------------------
//									Base object for all objects off our game
//---------------------------------------------------------------------------------------------------------------------
class GameObject
{

private:
	sf::Texture image;
	sf::Sprite sprite;
	bool _isLoaded;
	std::string fileName;
	sf::Vector2f position;
	int width;
	int height;
	float velocityX;
	float velocityY;
	

public:
	GameObject();
	virtual ~GameObject() = default;
	virtual void load(std::string fileName);
	virtual void draw(sf::RenderWindow& window);
	virtual void update(float elapsedTime);

	virtual void setPosition(float x, float y);
	virtual sf::Vector2f getPosition() const;
	virtual bool isLoaded() const;
	virtual float getWidth() const;
	virtual float getHeight() const;
	virtual sf::Rect<float> getBoundingRect() const;
protected:
	sf::Sprite& getSprite();
};
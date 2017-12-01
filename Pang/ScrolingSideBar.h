#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>


class SideScrollBar
{
public:
	const float containerWidth = 120;
	const float containerHeight = 40;
private:
	sf::RenderWindow *window;
	float maxValue;
	std::string name;
	std::string value;
	float currentPosition;
	float* currentValue;
	//float pivotPosition;
	sf::Vector2f position;					//posiotion of every element on the scren 
	sf::Vector2i localPosition;				//position of the mouse
	bool hitPivot = false;
	bool hide = false;
	sf::Font font;
	sf::Text label;
	sf::Text valueLabel;
	sf::RectangleShape container;
	sf::RectangleShape hideBox;				//A box that appear when we dont need our scroll bar 
	sf::RectangleShape line;
	sf::RectangleShape pivot;
	//bool hit(sf::Vector2i mousePosition, sf::RectangleShape rectangle);
public:
	static int counter;
	//SideScrollBar();
	SideScrollBar(float* startingValue, const float maxValue, const std::string name);
	void initialise(sf::RenderWindow &window);
	void update(sf::RenderWindow &window);
	void reduce(sf::RenderWindow& window);
private:
	void draw(sf::RenderWindow& window);
	void setPosition(sf::Vector2f position);
	void setPosition(float x, float y);
	bool hit(sf::Vector2i mousePosition, sf::RectangleShape rectangle);
	void move(sf::RenderWindow& window);

};
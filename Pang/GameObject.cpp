#include "GameObject.h"


GameObject::GameObject() : _isLoaded(false)
{
}
GameObject::~GameObject()
{
}
void GameObject::load(std::string fileName)
{
	if (!image.loadFromFile(fileName))
	{
		fileName = "";
		_isLoaded = false;
	}
	else
	{
		this->fileName = fileName;
		sprite.setTexture(image);
		_isLoaded = true;
	}
	
}
void GameObject::draw(sf::RenderWindow& window)
{
	if (_isLoaded)
	{
		window.draw(sprite);
	}
}
void GameObject::update(float elapsedTime)
{

}
void GameObject::setPosition(float x, float y)
{
	if (_isLoaded)
	{
		sprite.setPosition(x, y);
	}
}
sf::Vector2f GameObject::getPosition() const
{
	if (_isLoaded)
	{
		return sprite.getPosition();
	}
	return sf::Vector2f();
}
sf::Sprite& GameObject::getSprite()
{
	return sprite;
}
bool GameObject::isLoaded() const
{
	return _isLoaded;


}
float GameObject::getWidth() const
{
	return image.getSize().x;
}
float GameObject::getHeight() const
{
	return image.getSize().y;
}
sf::Rect<float> GameObject::getBoundingRect() const
{
	return sprite.getGlobalBounds();
}



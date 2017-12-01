#include "gameObjectManager.h"
#include "Game.h"
GameObjectManager::GameObjectManager()
{

}
GameObjectManager::~GameObjectManager()
{
	std::for_each(gameObjects.begin(),gameObjects.end(),GameObjectDeallocator());
}
void GameObjectManager::add(std::string name, GameObject * gameObject)
{
	gameObjects.insert(std::pair<std::string, GameObject*>(name, gameObject));
}
void GameObjectManager::remove(std::string name)
{
	std::map<std::string, GameObject*>::iterator result = gameObjects.find(name);
	if (result != gameObjects.end())
	{
		delete result->second;
		gameObjects.erase(result);
	}
}
GameObject* GameObjectManager::get(std::string name) const
{
	std::map<std::string, GameObject*>::const_iterator result = gameObjects.find(name);
	if (result == gameObjects.end())
	{
		return NULL;
	}
	return result->second;
}

int GameObjectManager::getObjectCount() const
{
	return gameObjects.size();
}
void GameObjectManager::drawAll(sf::RenderWindow& window)
{
	std::map<std::string, GameObject*>::const_iterator itr = gameObjects.begin();
	while (itr != gameObjects.end())
	{
		itr->second->draw(window);
		itr++;
	}
}
void GameObjectManager::updateAll()
{
	std::map < std::string, GameObject*>::const_iterator itr = gameObjects.begin();
	float timeDelta = elapsedTime.restart().asSeconds();
	while (itr != gameObjects.end())
	{
		itr->second->update(timeDelta);
		itr++;
	}
	
}
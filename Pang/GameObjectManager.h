#pragma once
#include "GameObject.h"

class GameObjectManager
{
public:
	GameObjectManager() = default;
	~GameObjectManager();
	sf::Clock elapsedTime;
	void add(std::string name, GameObject* gameObject);
	void remove(std::string name);
	int getObjectCount() const;
	GameObject* get(std::string name) const;

	void drawAll(sf::RenderWindow& window);
	void updateAll();
private:
	std::map<std::string, GameObject*> gameObjects;

	struct GameObjectDeallocator
	{
		void operator()(const std::pair<std::string, GameObject*> & p) const
		{
			 delete p.second;
		}
	};


};
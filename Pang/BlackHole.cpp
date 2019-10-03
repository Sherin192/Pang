#include "BlackHole.h"
#include <cstdlib>
BlackHole::BlackHole():size(32, 32)
{
	load("images/blackhole.png");
	getSprite().setOrigin(30, 27);
	srand(time(NULL));
	blackHoleBB.setSize(size);
	blackHoleBB.setOrigin(size.x / 2, size.y / 2);
	blackHoleBB.setPosition(rand() % 424 + 301, rand() % 668 + 50);
	getSprite().setPosition(blackHoleBB.getPosition());
	
}


sf::Rect<float> BlackHole::getBoundingRect() const
{
	return blackHoleBB.getGlobalBounds();
}

void BlackHole::update(float elapsedTime)
{
		Ball* ball = dynamic_cast<Ball*>(Game::getGameObjectManager().get("ball"));

		if (ball != NULL)					//If cast went fine procede
		{
			if (ball->getBoundingRect().intersects(getBoundingRect()) && !hit)
			{
				// those numbers are the max and min coordinates that the black hole can appear 
				blackHoleBB.setPosition(rand() % 424 + 301, rand() % 668 + 50); 
				getSprite().setPosition(blackHoleBB.getPosition());			
				ball->setPosition(blackHoleBB.getPosition().x, blackHoleBB.getPosition().y);

				//if there was an intersection it turns true so this if statement will run only once per intersection
				hit = true;		
			}
			else if (!(ball->getBoundingRect().intersects(getBoundingRect())) && hit)
			{
				//if there is no intersection and hit is true it turns it off so it will be redy for the next one
				hit = false;
			}
		
		}
}

#pragma once
//#include "GameObject.h"
#include "ball.h"
//---------------------------------------------------------------------------------------------------------------------
/*				Black Hole is and addictional feature that makes appear a black hole on the screen and 
				when the ball intersecates with the hole it moves to a random place on the screen 
				together with the ball which continues it's movement form the new position. After the 
				ball left the black hole it is redy to teleport to a new position whenever it intersecates 
				with the ball again.

				This feature can be turn on or off in the menu. This gives the player the ability to chose
				whether he wants to play with this feature or not.
*/
//---------------------------------------------------------------------------------------------------------------------
class BlackHole:public GameObject
{
	//private members
	bool hit = false;							//allowes only one teleport for intersection
	const sf::Vector2f size;					//size of the Bounding Rect
	sf::RectangleShape blackHoleBB;				//bounding box, I don't use the sprite.boundingRect because it's to big

public:
	BlackHole();
	~BlackHole();
	void update(float elapsedTime);			
private:
	sf::Rect<float> getBoundingRect() const;	//overrided method from the base class to return blackHoleBB
};
#include "ball.h"
#include <cstdlib>

Ball::Ball() :elapsedTimeSinceStart(0.0f), moveX(0.0f), moveY(0.0f), velocity(330.0f), maxVelocity(500.0f)
{
	load("images/yellow-ball-30.png");
	buffer.loadFromFile("sound.wav");
	sound.setBuffer(buffer);
	losebuffer.loadFromFile("losepoint.wav");
	losepoint.setBuffer(losebuffer);
	//sound.play();
	getSprite().setOrigin(15, 15);
	srand(time(NULL));
	angle = float(rand() % 360 + 1);
	minVelocity = velocity;
}
Ball::~Ball()
{
}
void Ball::update(float elapsedTime)
{
	bool colision = false;
	elapsedTimeSinceStart += elapsedTime;
	if (elapsedTimeSinceStart < 4.0f)
		return;
	if (elapsedTimeSinceStart > 64.0f && !increase)
	{
		velocity += 20;
		increase = true;
	}

	float moveAmount = velocity * elapsedTime;

	moveX = linearVelocityX(angle) * moveAmount;
	moveY = linearVelocityY(angle) * moveAmount;
	//-----------------------------------------------------------------------------------------------------------------
	//--------------------------------- Collision with upper and lower wall -------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------
	if (getPosition().y + moveY <= 0 + 15 || getPosition().y + moveY >= HEIGHT - 15)
	{

		angle = 360.0f - angle;

		if (angle < 0.0f) angle += 360.0f;
		if (angle > 360.0f) angle -= 360.0f;

		if (angle > 260.0f && angle < 270.0f) angle -= 5.0f + float(rand() % 5 + 1);
		if (angle > 270.0f && angle < 280.0f) angle += 5.0f + float(rand() % 5 + 1);
		if (angle == 90 || angle == 270) angle += 1;
		if (angle > 80.0f && angle < 90.0f) angle -= 5.0f + float(rand() % 5 + 1);
		if (angle > 90.0f && angle < 100.0f) angle += 5.0f + float(rand() % 5 + 1);

		moveY = -moveY;
	}
	//-----------------------------------------------------------------------------------------------------------------
	//--------------------------------------- Collision with paddles --------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------

	Paddle* player1 = dynamic_cast<Paddle*>(Game::getGameObjectManager().get("Paddle1"));

	if (player1 != NULL)									//If cast went fine procede
	{
		if (colliision(player1->getBoundingRect(), getBoundingRect(), player1->getPosition(), getPosition()))
		{
			std::cout << angle << std::endl;
			if (player1->getVelocity() > 0 && angle < 255 && angle > 75)
				angle -= float(rand() % 10 + 1);
			else if (player1->getVelocity() < 0 && angle < 255 && angle > 75)
				angle += float(rand() % 10 + 1);
			std::cout << angle << std::endl;
		}
	}

	PaddleAI* playerAI = dynamic_cast<PaddleAI*>(Game::getGameObjectManager().get("PaddleAI"));

	if (playerAI != NULL)									//If cast went fine procede
	{
		if (colliision(playerAI->getBoundingRect(), getBoundingRect(), playerAI->getPosition(), getPosition()))
		{
			std::cout << angle << std::endl;
			if (playerAI->getVelocity() > 0 && angle < 255 && angle > 75)
			{
					angle -= float(rand() % 10 + 1);
			}
			else if (playerAI->getVelocity() < 0 && angle < 255 && angle > 75)
			{
					angle += float(rand() % 10 + 1);
			}
			std::cout << angle << std::endl;
		}
	}

	//-----------------------------------------------------------------------------------------------------------------
	//----------------------------------- Collision with left and right wall ------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------

	// Ball hit left side of the screen 
	if (getPosition().x + moveX <= 15)
	{
		elapsedTimeSinceStart = 4.0f;
		velocity = minVelocity;
		losepoint.play();
		Game::PlayerScore++;								//increment Players score
		setPosition(WIDTH / 2, HEIGHT / 2);					//return the ball to the center of the screan
		angle = float(rand() % 360 + 1);					//set random angle
	}

	// Ball hit right side of the screen 
	if (getPosition().x + moveX >= WIDTH)
	{
		elapsedTimeSinceStart = 4.0f;
		velocity = minVelocity;
		losepoint.play();
		Game::AIScore++;									//increment Players score
		setPosition(WIDTH / 2, HEIGHT / 2);					//return the ball to the center of the screan
		angle = rand() % 360 + 1;							//set random angle
	}

	getSprite().move(moveX, moveY);							//move the sprite after all modifications
}
float Ball::linearVelocityX(float angle)
{
	//radians = degrees * PI / 180
	//cos(angle) = the x coordinate
	if (angle < 0) angle = 360 + angle;
	return (float)std::cos(angle * (3.1415926 / 180));		
}
float Ball::linearVelocityY(float angle)
{
	//radians = degrees * PI / 180
	//sin(angle) = the y coordinate
	if (angle < 0) angle = 360 + angle;
	return (float)std::sin(angle * (3.1415926 / 180));
}
bool Ball::colliision(sf::FloatRect bb1, sf::FloatRect bb2, sf::Vector2f pos1, sf::Vector2f pos2)
{
	sf::FloatRect overlap;									//will contain the overlaping rectangle from a collision
	sf::Vector2f result{ 0, 0 };
	if(bb1.intersects(bb2, overlap))						//checks for intersection
	{ 
		sound.play();										//souds bounce sound 

		if (overlap.height > overlap.width)					//collision on x axis 
		{
			angle = 360.0f - (angle - 180.0f);				//change the angle 

			if (angle < 0.0f) angle += 360.0f;				
			if (angle > 360.0f) angle -= 360.0f;			//make sure angle is between 0 and 360 degrees

			if (angle > 350.0f && angle <= 360.0f)						//make sure the angle is not to vertical 
				 angle -= 10.0f + float(rand() % 15 + 1);
			if (angle > 0.0f &&	angle < 10.0f)							//make sure the angle is not to vertical 
				 angle += 10.0f + float(rand() % 15 + 1);
			
			if (pos1.x - pos2.x < 0)						//paddle is more left than ball, collision <--
			{
				getSprite().move(overlap.width, 0);			//so we move the ball --> on x axis by penetration 
			}
			else											//paddle is more right than ball, collision -->
			{
				getSprite().move(-overlap.width, 0);		//so we move the ball <-- on x axis by -penetration
				
			}
			moveX = -moveX;									//invert the movment value
		}
		else												//collision on y axis
		{
			angle = 360.0f - angle;							//modify the angle

			if (angle < 0.0f) angle += 360.0f;				
			if (angle > 360.0f) angle -= 360.0f;			//make sure angle is between 0 and 360 degrees

			if (angle > 350.0f && angle < 360.0f) angle -= 20.0f;
			if (angle > 0.0f && angle < 10.0f) angle += 20.0f;

				if (pos1.y - pos2.y < 0)					//paddle is higher than the ball, collision form bottom
				{
					
					getSprite().move(0, overlap.height);	//so move the ball down by penetration 
				}
				else										//paddle is under the ball, collision form top
				{
					getSprite().move(0, -overlap.height);	//so move the ball up by -penetration
				}
			moveY = -moveY;									//invert the y movment
		}
		return true;
	}
	return false;
}

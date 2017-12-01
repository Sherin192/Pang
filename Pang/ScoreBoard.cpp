#include "ScoreBoard.h"

ScoreBoard::ScoreBoard(std::string ID)
{
	this->ID = ID;
	load("images/numbers.png");
	getSprite().setTextureRect(sf::IntRect(3, 1, 62, 86));
	getSprite().setOrigin(31, 44);
	
}
void ScoreBoard::update(float score)
{
	if(this->ID == "player1")
		getSprite().setTextureRect(sf::IntRect(3 + 62 * Game::PlayerScore , 1, 62, 86));
	else if (this->ID == "playerAI")
		getSprite().setTextureRect(sf::IntRect(3 + 62 * Game::AIScore, 1, 62, 86));
	/*Paddle* player1 = dynamic_cast<Paddle*>(Game::getGameObjectManager().get("Paddle1"));
	std::cout << "score = " << player1->score << std::endl;
	getSprite().setTextureRect(sf::IntRect(53 * player1->score, 0, 53, 63));
	Paddle* player2 = dynamic_cast<Paddle*>(Game::getGameObjectManager().get("Paddle2"));
	getSprite().setTextureRect(sf::IntRect(53 * player2->score, 0, 53, 63));*/
}


//#include "GameObject.h"
//#include "ball.h"
#include "Globals.h"
#include "Game.h"
//#include "Paddle.h"
//#include <sstream>


int main()
{
	Game::Start();
	/*sf::RenderWindow window;
	window.create(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
	SplashScreen img;
	img.Show(window);*/
	/*std::ostringstream ss;
	
	sf::Text score;
	
	sf::Font font;
	if (!font.loadFromFile("vtks giz.ttf"))
	{
		// error...
	}
	sf::Text text;
	score.setFont(font);
	
	ss << P1_score << " " << P2_score;
	score.setString(ss.str());
	score.setPosition(sf::Vector2f(WIDTH / 2 - 10, 40));
	// select the font
	text.setFont(font); // font is a sf::Font

						// set the string to display
	text.setString("Score");

	// set the character size
	score.setCharacterSize(20);
	score.setColor(sf::Color::Blue);
	text.setCharacterSize(20);
	text.setColor(sf::Color::Blue);

	// set the text style
	text.setPosition(sf::Vector2f(WIDTH / 2 -20, 10));
	
	Ball ball;
	Paddle paddle1, paddle2;
	ball.init(window);
	paddle1.init(window, 50, WIDTH/2);
	paddle2.init(window, 750, WIDTH / 2);
	
		window.clear();
		paddle1.move();
		paddle2.move();
		ball.start();
		ball.isColision(paddle1.getPosition());
		ball.isColision(paddle2.getPosition());
		paddle1.update();
		paddle2.update();
		ball.update();
		ball.draw();
		paddle1.draw();
		paddle2.draw();
		window.draw(text);
		window.draw(score);
		
	}*/
	return 0;
}
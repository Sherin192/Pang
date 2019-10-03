#include "Game.h"
#include "Globals.h"

void Game::Start()
{
	if (gameState != Uninzialized)
	{
		return;
	}
	float *vel = new float;
	AIScore = 0;
	PlayerScore = 0;
	window.create(sf::VideoMode(WIDTH, HEIGHT, 32), "SFML works!");
	//-----------------------------------------------------------------------------------------------------------------
	//------------------------------------ Create the objects of the game ---------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------

	Paddle* player1 = new Paddle();
	PaddleAI* playerAI = new PaddleAI();
	BlackHole* blackHole = new BlackHole();
	Ball* ball = new Ball();
	ScoreBoard* PlayerScore = new ScoreBoard("player1");
	ScoreBoard* AIScore = new ScoreBoard("playerAI");
	CountDown* cd = new CountDown();

	//Tool to modify the velocity of the ball in runtime can be applied to olther elements if needed
	#ifdef DEBUG
	vel = &ball->velocity;
	float maxVel = ball->maxVelocity;
	bar = new SideScrollBar(vel, maxVel, "velocity");
	bar->initialise(window);
	#endif

	//-----------------------------------------------------------------------------------------------------------------
	//------------------------------ Initialize the position of game elements -----------------------------------------
	//-----------------------------------------------------------------------------------------------------------------

	player1->setPosition(WIDTH - 40, HEIGHT / 2);
	playerAI->setPosition(40, HEIGHT / 2);
	ball->setPosition(WIDTH / 2, (HEIGHT / 2) - 15);
	PlayerScore->setPosition(WIDTH / 2 + 50, 40);
	AIScore->setPosition(WIDTH / 2 - 50, 40);
	cd->setPosition(WIDTH / 2, (HEIGHT / 2));
	
	//-----------------------------------------------------------------------------------------------------------------
	//--------------------------------- Add the objects to the game manager -------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------

	gameObjectManager.add("Paddle1", player1);
	gameObjectManager.add("PaddleAI", playerAI);
	gameObjectManager.add("BlackHole", blackHole);
	gameObjectManager.add("ball", ball);
	gameObjectManager.add("scorePlayer", PlayerScore);
	gameObjectManager.add("scoreAI", AIScore);
	gameObjectManager.add("cd", cd);

	//-----------------------------------------------------------------------------------------------------------------
	//---------------------------------------------- End --------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------

	gameState = ShowingMenu;
	music.openFromFile("intro.ogg");
	music.setLoop(true);
	music.play();
	CountDown::elapsedTime = 0.0f;							//sets the count down time to 0

	while (!IsExiting())									//main loop
	{
		GameLoop();
	}
	window.close();
}
//----------------------------------------------- END OF START() ------------------------------------------------------

bool Game::IsExiting()
{
	if (gameState == Exiting)
		return true;
	else
		return false;
}
//-------------------------------------------- END OF ISEXITING() -----------------------------------------------------

void Game::GameLoop()
{
	sf::Event CurrentEvent;

	window.pollEvent(CurrentEvent);

		switch (gameState)									//game state manager
		{
			case Game::ShowingMenu:							// shows the menu 
			{
				ShowMainMenu();
				break;
			}
			case Game::Playing:								//runs the game
			{
				if (!BH)									//if the blackHole wasn't selected
					gameObjectManager.remove("BlackHole");	//it removes it form the manager

					window.clear(sf::Color::Green);	

					//allowes to hide the tool if wanted 
					#ifdef DEBUG
					if (CurrentEvent.type == sf::Event::MouseButtonReleased)
					{	
						bar->reduce(window);
					}
					#endif		

					if (CountDown::elapsedTime > 4.0f)		//if the countDown has finished 
						gameObjectManager.remove("cd");		//it removes it from the manager

					gameObjectManager.updateAll();			//updates all object in the manager
					
					//updates the tool 
					#ifdef DEBUG
					bar->update(window);				
					#endif

					gameObjectManager.drawAll(window);		// draws all objects in the manager
					window.display();						//and displsys them 

					if (PlayerScore == 10 || AIScore == 10)
					{
						gameState = WinScrean;
					}
					if (CurrentEvent.type == sf::Event::Closed)
						gameState = Exiting;

					if (CurrentEvent.type == sf::Event::KeyPressed)
					{
						if (CurrentEvent.key.code == sf::Keyboard::Escape)
							ShowMainMenu();
					}
				break;
			} 
			case Game::WinScrean:
			{
				music.pause();
				if (CurrentEvent.type == sf::Event::Closed)
					gameState = Exiting;

				if (CurrentEvent.type == sf::Event::KeyPressed)
				{
					if (CurrentEvent.key.code == sf::Keyboard::Escape)
						ShowMainMenu();
				}
				sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
				if (PlayerScore == 10)
				{
					EndScreen* winScreen = new EndScreen("images/youwin.png");
					winScreen->Show(window);
					if (CurrentEvent.type == sf::Event::MouseButtonPressed)
					{
						if (winScreen->hit(mousePosition))
						{
							gameObjectManager.remove("Paddle1");
							gameObjectManager.remove("PaddleAI");
							gameObjectManager.remove("ball");
							gameObjectManager.remove("scorePlayer");
							gameObjectManager.remove("scoreAI");
							gameState = Uninzialized;
							Game::Start();
						}
					}
			}
			else if (AIScore == 10)
			{
				EndScreen* loseScreen = new EndScreen("images/youlose.png");
				loseScreen->Show(window);
				if (CurrentEvent.type == sf::Event::MouseButtonPressed)
				{
					if (loseScreen->hit(mousePosition))
					{
						gameObjectManager.remove("Paddle1");
						gameObjectManager.remove("PaddleAI");
						gameObjectManager.remove("ball");
						gameObjectManager.remove("scorePlayer");
						gameObjectManager.remove("scoreAI");
						gameState = Uninzialized;
						Game::Start();
					}
				}
			}
			break;
			}
		}
		
}
//-------------------------------------------- END OF GAMELOOP() ------------------------------------------------------

void Game::ShowMainMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(window);
	BH = mainMenu.isBH();
	switch (result)
	{
	case MainMenu::Play:
		gameState = Game::Playing;
		music.openFromFile("level1.ogg");
		music.play();
		gameObjectManager.elapsedTime.restart();
		break;
	case MainMenu::Exit:
		gameState = Game::Exiting;
		break;
	}
}





const GameObjectManager& Game::getGameObjectManager()
{
	return Game::gameObjectManager;
}


unsigned int Game::AIScore = 0;
unsigned int Game:: PlayerScore = 0;
Game::GameState Game::gameState = Game::Uninzialized;
sf::RenderWindow Game::window;
GameObjectManager Game::gameObjectManager;
bool Game::BH = false;
sf::Music Game::music;
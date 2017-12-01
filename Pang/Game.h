#pragma once
#include <stdio.h>
#include "SplashScreen.h"
#include "MainMenu.h"
#include "CheckBox.h"
#include "Paddle.h"
#include "paddleAI.h"
#include "ball.h"
#include "BlackHole.h"
#include "ScoreBoard.h"
#include "CountDown.h"
#include "EndScreen.h"
#include "ScrolingSideBar.h"
#include "GameObjectManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//#define DEBUG
class Game
{
	enum GameState {Uninzialized, Paused, ShowingMenu, Playing, WinScrean, Exiting};
	static GameState gameState;
	static sf::RenderWindow window;
public:
	#ifdef DEBUG
	static SideScrollBar* bar;
	#endif // DEBUG
	static sf::Music music;
	static MainMenu mainMenu;
	static unsigned int AIScore;
	static unsigned int PlayerScore;
	//static float elapsedTimeSinceStart;
	static void Start();
	const static GameObjectManager& Game::getGameObjectManager();
	//static float getElapsedTime();
private:
	//static bool splashShowed;
	static bool BH;
	//static void ShowSplashScreen();
	static void ShowMainMenu();
	static bool IsExiting();
	static void GameLoop();
	static GameObjectManager gameObjectManager;
};

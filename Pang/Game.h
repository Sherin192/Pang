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
	static sf::Music music;
	static MainMenu mainMenu;
	static unsigned int AIScore;
	static unsigned int PlayerScore;
	static void Start();
	const static GameObjectManager& Game::getGameObjectManager();
private:
	static bool BH;
	static void ShowMainMenu();
	static bool IsExiting();
	static void GameLoop();
	static GameObjectManager gameObjectManager;
};

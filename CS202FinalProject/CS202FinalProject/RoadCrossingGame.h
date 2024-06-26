#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <vector>

#include "Road.h"
#include "Player.h"
#include "Timer.h"
#include "Effects.h"
#include "VehicleRoad.h"
#include "InputTextBox.h"
#include "GameOptions.h"
#include "GardenRoad.h"
#include "GameInformationDisplay.h"

enum GAME_STATUS {
	CURRENT_PLAYED = 0,
	PAUSED = 1,
	LOSE = 2,
	WIN = 3
};

class RoadCrossingGame {
private:

	Timer timer;	
	GameOptions* gameOptions;
	Effects effects;
	GameInformationDislay gameInformationDisplay;
	sf::RenderWindow &window;
	double dTime; // calculate the elapsed time after each update(), used for animation frames updating.

	std::vector<Road*> roads;
	Player player;

	sf::Vector2f generalPosition;

	sf::Sprite statusImage;

	std::vector<sf::Texture> carModels;
	std::vector<sf::Texture> animalModels;

	int levelID;
	GAME_STATUS status;

	void setPositionsOfRoads();
	//bool updateLevel(const int newLevelID);
	bool updateLevel(const int newLevelID);
	void initializePlayer();
	void initializeLevel();
	void initializeTimer();

	void clearRoads();

public:

	const static unsigned MAX_NUM_CAR_MODELS = 7;
	const static unsigned MAX_NUM_ROADS = 30;

	RoadCrossingGame(sf::RenderWindow &window,GameOptions* gameOptions);
	RoadCrossingGame(sf::RenderWindow &window, const bool savedOldGame, GameOptions* gameOptions);

	~RoadCrossingGame();

	void render(sf::RenderTarget * const window);
	void update();
	void updateWithEvent(const sf::Event &event);
	bool saveGameToTextFile();
	bool saveGameToTextFile(const std::string &path);
	bool readGameFromTextFile();
	bool readGameFromTextFile(const std::string &path);
	GAME_STATUS getGameStatus() const;
	void pauseGame();
	void continueGame();
	void resetCurrentLevel();
	void moveNextLevel();
	double getRecordTime();

};
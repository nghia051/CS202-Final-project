#include <fstream>
#include <iostream>

#include "Helper.h"
#include "RoadCrossingGame.h"

void RoadCrossingGame::setPositionsOfRoads() {
	sf::Vector2f position(300, 0);
	for (SimpleRoad &road : (this->roads)) {
		road.setRoadPosition(position);
		std::cerr << "Position of road is set to " << position.x << ' ' << position.y << '\n';
		position.x += 100;
	}
};

RoadCrossingGame::RoadCrossingGame(): player("Data/Images/player.png") {
	(this -> levelID) = 0;
	this->updateLevel(this -> levelID);

	//(this -> player) = Player("Data/Images/player.png");
	(this -> player).setPosition(200, 400);
	(this -> player).setSpeed(100);
};

RoadCrossingGame::~RoadCrossingGame() {};

bool RoadCrossingGame::updateLevel(const int newLevelID) {
	//(this->levelID) = newLevelID;
	const std::string path = "Data/Levels/level_" + Helper::convertIntToString(newLevelID) + ".txt";
	std::ifstream inputFile(path.c_str());
	const bool result = inputFile.is_open();
	if (result) {
		double speed;
		int numberOfRoads, numberOfObstacles;
		std::cerr << "Path \"" << path << "\" is opened successfully" << '\n';
		inputFile >> numberOfRoads;
		(this -> roads).resize(numberOfRoads + 2);
		this -> setPositionsOfRoads();
		for (int i = 1; i <= numberOfRoads; ++i) {
			inputFile >> numberOfObstacles;
			for (int j = 0; j < numberOfObstacles; ++j) {
				inputFile >> speed;
				(this->roads)[i].appendCarWithSpeed(speed);
			}
		}
	} else
		std::cerr << "Path \"" << path << "\" is not opened successfully" << '\n';
	inputFile.close();
	return result;
}

void RoadCrossingGame::render(sf::RenderTarget * const window) {
	for (SimpleRoad& road : (this -> roads))
		road.render(window);
	(this->player).render(window);
};

void RoadCrossingGame::update() {
	for (SimpleRoad& road : (this->roads))
		road.update();
};

bool RoadCrossingGame::saveGameToTextFile() {
	const std::string path = "Data/SaveGame/saveGame.txt";
	std::ofstream outputFile(path.c_str());
	const bool result = outputFile.is_open();
	if (result) {
		outputFile << (this -> levelID) << '\n';
	} else
		std::cerr << "Path \"" << path << "\" is not opened successfully" << '\n';
	outputFile.close();
	return result;
};
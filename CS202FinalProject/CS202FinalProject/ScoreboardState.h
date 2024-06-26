#pragma once

#include <vector>
#include <string>
#include <fstream>

#include "Scoreboard.h"
#include "State.h"
#include "Button.h"
#include "Box.h"

class ScoreboardState : public State {
private:
	sf::Texture backgroundTexture;
	sf::RectangleShape background;

	std::map<std::string, Button*> buttons;
	std::vector<std::vector<double> > score;

	void initializeBackground();
	void initializeButtons();
	void loadScore();
	void saveScore();
	void resetScoreboard();
public:
	ScoreboardState(sf::RenderWindow* const window, std::vector<State*>* states);
	ScoreboardState(sf::RenderWindow* const window, std::vector<State*>* states, GameOptions* gameOptions);

	void updateEvents();

	void update();

	void render(sf::RenderWindow* const target);

	virtual ~ScoreboardState();
};
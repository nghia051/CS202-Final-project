#pragma once

#include "Button.h"
#include "State.h"
#include "GameState.h"

class PlayMenuState : public State {
private:
	sf::Texture backgroundTexture;
	sf::RectangleShape background;

	std::map<std::string, Button*> buttons;

	void initializeBackground();
	void initializeButtons();

public:

	PlayMenuState(sf::RenderWindow* const window, std::vector<State*>* states);
	PlayMenuState(sf::RenderWindow* const window, std::vector<State*>* states, GameOptions* gameOptions);
	
	virtual ~PlayMenuState();

	void updateEvents();
	void update();
	void render(sf::RenderWindow* target);
};
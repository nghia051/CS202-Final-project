#pragma once

#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Audio/Sound.hpp>

#include "Obstacle.h"
#include "Animation.h"

enum Player_animationIndex {idle, move_down, move_left, move_right, move_up};
enum PLAYER_STATUS {CONSCIOUS = 0, POISONED = 1};

class Player {	
private:
	sf::Sound sound;
	sf::Sprite model;
	sf::Texture texture;
	sf::RectangleShape hitbox;
	std::vector<Animation> animations;
	int currentAnimation;
	double speed;
	PLAYER_STATUS status;

public:

	sf::Vector2f velocity;
	
	//----------Constructors--------------------//
	Player();
	
	Player(const std::string &model_file_path, int num_frames = 0, float anim_duration = 0.0, int num_anims = 5); //


	//----------Member Functions---------------//

	//
	void render(sf::RenderTarget* const rdTarget) const;

	// Set the object's speed
	bool setSpeed(double speed);
	// Returns the object's speed
	double getSpeed() const;
	// Set the object's position
	void setPosition(const sf::Vector2f pos);
	void setPosition(float X, float Y);
	/* Get the object's position */
	sf::Vector2f getPosition() const;

	sf::FloatRect getBounds() const;

	//bool checkCollision(const Player& other) const;
	bool checkCollision(const Obstacle &obstacle) const;
	void setHitboxPosition();
	
	/* Object's Movement functions */
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	bool moveLeft(const double lowerBound, const double upperBound);
	bool moveRight(const double lowerBound, const double upperBound);
	bool moveUp(const double lowerBound, const double upperBound);
	bool moveDown(const double lowerBound, const double upperBound);
	bool move(float dTime, const double lowerBoundY, const double upperBoundY, const double lowerBoundX, const double upperBoundX);
	
	void stop();

	double getHeight() const;
	double getWidth() const;

	void saveToTextFile(std::ofstream &outputFile) const;
	void readFromTextFile(std::ifstream& inputFile);

	PLAYER_STATUS getStatus() const;
	void setStatus(const PLAYER_STATUS status);

	friend std::ostream& operator << (std::ostream& outputStream, const Player& player);
};
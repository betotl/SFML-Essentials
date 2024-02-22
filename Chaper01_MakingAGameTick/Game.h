#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>


class Game {
public:
	Game();
	~Game();
	void run();

// main methods
private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();

// auxiliar methods
private:
	void handleInput(sf::Keyboard::Key key, bool isPressed);

// Variables
private:
	const int mWINDOW_WIDTH = 640;
	const int mWINDOW_HEIGHT = 480;
	const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);
	bool mIsMovingUp = false;
	bool mIsMovingDown = false;
	bool mIsMovingLeft = false;
	bool mIsMovingRight = false;

// Game Objects
private:
	sf::RenderWindow mWindow;
	sf::Texture mPlayerTexture;
	sf::Sprite mPlayerSprite;
};


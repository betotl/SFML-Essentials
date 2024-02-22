#include "Game.h"


Game::Game(): 
	mWindow(sf::VideoMode(mWINDOW_WIDTH, mWINDOW_HEIGHT), "Hello World"),
	mPlayerTexture(),
	mPlayerSprite() {

	// Player Texture and Sprite
	if (!mPlayerTexture.loadFromFile("Media/Textures/Eagle.png")) {
		// Handle Error
	}
	mPlayerSprite.setTexture(mPlayerTexture);
	mPlayerSprite.setPosition(100.f, 100.f);
	
}

Game::~Game() {

}

void Game::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen()) {
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TIME_PER_FRAME) {
			timeSinceLastUpdate -= TIME_PER_FRAME;
			processEvents();
			update(TIME_PER_FRAME);
		}
		render();
	}
}

// Process the events of the game
void Game::processEvents() {
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		switch (event.type) {
			case sf::Event::KeyPressed:
				handleInput(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				handleInput(event.key.code, false);
				break;
			case sf::Event::Closed:
				mWindow.close();
				break;
		}
		if (event.type == sf::Event::Closed) {
			mWindow.close();
		}
	}
}

// Updates variables, positions, items in the game
void Game::update(sf::Time deltaTime) {
	sf::Vector2f movement(0.f, 0.f);
	if (mIsMovingUp)
		movement.y -= 1.f;
	if (mIsMovingDown)
		movement.y += 1.f;
	if (mIsMovingLeft)
		movement.x -= 1.f;
	if (mIsMovingRight)
		movement.x += 1.f;

	mPlayerSprite.move(movement * deltaTime.asSeconds());
}

// Renders the display in the windows.
void Game::render() {
	mWindow.clear();
	mWindow.draw(mPlayerSprite);
	mWindow.display();

	std::cout << "Position: " << mPlayerSprite.getPosition().x << " " << mPlayerSprite.getPosition().y << '\n';
}



void Game::handleInput(sf::Keyboard::Key key, bool isPressed) {
	switch (key) {
		case sf::Keyboard::Key::W:
			mIsMovingUp = isPressed;
			break;
		case sf::Keyboard::Key::S:
			mIsMovingDown = isPressed;
			break;
		case sf::Keyboard::Key::A:
			mIsMovingLeft = isPressed;
			break;
		case sf::Keyboard::Key::D:
			mIsMovingRight = isPressed;
			break;
	}
}


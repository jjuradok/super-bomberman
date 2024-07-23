#include "Bomb.h"
#include "../config/Constants.h"
#include "../config/ResourcesLocation/ResourcesLocation.h"
#include <iostream>

class Animated;

Bomb::Bomb(char playerOrigin) : ::Animated(Vector2f(0, 0), BOMB_TEXTURE_P1_FOLDER, BOMB_ANIMATION_FRAMES) {
	playerOrigin = playerOrigin;
	bool isPlayerOne = playerOrigin == PLAYER_ONE_ID;
	if (!isPlayerOne) this->updateFolder(BOMB_TEXTURE_P2_FOLDER);
	bombClock.restart();
}

void Bomb::draw(RenderWindow &w) {
	w.draw(this->getSprite());
}

Vector2f Bomb::getPosition ( ) {
	return this->getSprite().getPosition();
}

void Bomb::changePosition(Vector2f newPosition) {
	this->getSprite().setPosition(newPosition);
}

bool Bomb::shouldExplode() {
	if (isPaused) {
		return false;
	}
	return (bombClock.getElapsedTime().asMilliseconds() >= timeRemaining);
}
void Bomb::setPaused(bool paused) {
	if (paused) {
		if (!isPaused) {
			timeRemaining -= bombClock.getElapsedTime().asMilliseconds();
			isPaused = true;
		}
	} else {
		if (isPaused) {
			isPaused = false;
			bombClock.restart();
		}
	}
}

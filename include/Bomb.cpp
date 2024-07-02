#include "Bomb.h"
#include "config/Constants.h"
#include "config/Config.h"
#include "config/ResourcesLocation.h"
#include <iostream>

Bomb::Bomb(char playerOrigin) {
	cout << "origin: " << playerOrigin << endl;
	playerOrigin = playerOrigin;
	
	bool isPlayerOne = playerOrigin == PLAYER_ONE_ID;
	string bombTexturePath = isPlayerOne ? BOMB_TEXTURE : BOMB_PLAYER_TWO_TEXTURE;
	cout << "path" << bombTexturePath << endl;
	
	bombTexture.loadFromFile(bombTexturePath);
	bombSprite.setTexture(bombTexture);
	bombSprite.setScale(SCALE_FACTOR, SCALE_FACTOR);
}

void Bomb::update ( ) {
	// mostrar animacion
}

void Bomb::draw(RenderWindow &w) {
	w.draw(bombSprite);
}

Vector2f Bomb::verPosicion ( ) {
	return bombSprite.getPosition();
}

void Bomb::changePosition(Vector2f newPosition) {
	bombSprite.setPosition(newPosition);
}

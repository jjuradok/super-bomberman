#include "Bomb.h"
#include "config/Constants.h"
#include "config/Config.h"
#include "config/ResourcesLocation.h"
#include <iostream>


Bomb::Bomb(char playerOrigin) {
	playerOrigin = playerOrigin;
	
	bool isPlayerOne = playerOrigin == PLAYER_ONE_ID;
	textureFolderPath = isPlayerOne ? BOMB_TEXTURE_P1_FOLDER : BOMB_TEXTURE_P2_FOLDER;
	string texturePath = textureFolderPath + to_string(textureCurrentFrame) + ".png";

	bombTexture.loadFromFile(texturePath);
	bombSprite.setTexture(bombTexture);
	bombSprite.setScale(SCALE_FACTOR, SCALE_FACTOR);
}

void Bomb::draw(RenderWindow &w) {
	w.draw(bombSprite);
}

Vector2f Bomb::getPosition ( ) {
	return bombSprite.getPosition();
}

void Bomb::changePosition(Vector2f newPosition) {
	bombSprite.setPosition(newPosition);
}

bool Bomb::shouldExplode() {
	return (bombClock.getElapsedTime().asMilliseconds() >= BOMB_LIFE_TIME);
}

void Bomb::update()
{
	if (textureTime.getElapsedTime().asMilliseconds() >= ANIMATION_FRAME_DURATION)
	{
		if (shouldIncreaseFrame)
		{
			textureCurrentFrame++;
		}
		else
		{
			textureCurrentFrame--;
		}
		if (textureCurrentFrame == BOMB_ANIMATION_FRAMES - 1)
		{
			shouldIncreaseFrame = false;
		}
		if (textureCurrentFrame == 0)
		{
			shouldIncreaseFrame = true;
		}
		string texturePath = textureFolderPath + to_string(textureCurrentFrame) + ".png";
		bombTexture.loadFromFile(texturePath);
		bombSprite.setTexture(bombTexture);
		textureTime.restart();
	}
}
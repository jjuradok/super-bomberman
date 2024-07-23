#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
#include <iostream>
#include "../config/Config.h"
#include "../config/ResourcesLocation.h"
#include "../config/Constants.h"
#include "../utils/Boundings.h"

class Animated;
using namespace std;
using namespace sf;

Player::Player(bool isPlayerOne, Vector2f position) : ::Animated(position, P1_TEXTURE_DOWN_FOLDER, PLAYER_ANIMATION_FRAMES), isPlayerOne(isPlayerOne)
{
	this->resetAnimation(PLAYER_TEXTURE_DOWN_DEFAULT_FRAME);
	if (!isPlayerOne) updateFolder(P2_TEXTURE_DOWN_FOLDER);

	int textureWidth = PLAYER_TEXTURE_WIDTH;
	int textureHeight = PLAYER_TEXTURE_HEIGHT;
	int spriteWidth = TILE_SIZE;
	int spriteHeight = TILE_SIZE;

	this->getSprite().setOrigin(0, 0);

	this->getSprite().setScale(PLAYER_SCALE_FACTOR, PLAYER_SCALE_FACTOR);
	if (isPlayerOne)
	{
		m_right = Keyboard::D;
		m_left = Keyboard::A;
		m_up = Keyboard::W;
		m_down = Keyboard::S;
		m_shoot = Keyboard::F;
	}
	else
	{
		m_right = Keyboard::Right;
		m_left = Keyboard::Left;
		m_up = Keyboard::Up;
		m_down = Keyboard::Down;
		m_shoot = Keyboard::Space;
	}
}

FloatRect Player::getCollisionBounds()
{
	float collisionY = this->getSprite().getPosition().y + TILE_SIZE * PLAYER_SCALE_FACTOR - TILE_SIZE * PLAYER_SCALE_FACTOR / 2;
	FloatRect collisionRect = FloatRect(this->getSprite().getPosition().x, collisionY, TILE_SIZE * PLAYER_SCALE_FACTOR, TILE_SIZE * PLAYER_SCALE_FACTOR);
	return collisionRect;
}

bool Player::checkCollision(vector<FloatRect> boundings, Vector2f movement)
{
	FloatRect futureBounds = this->getCollisionBounds();
	futureBounds.left += movement.x;
	futureBounds.top += movement.y;

	for (FloatRect bounding : boundings)
	{
		if (bounding.intersects(futureBounds))
		{
			return true;
		}
	}
	return false;
}

// void Player::update(Level &level)
// {
// 	Vector2f movement(0.f, 0.f);
// 	vector<FloatRect> boxesBoundings = getBoundingsFromEntities(level.getLevelBoxes());
// 	bool isMoving = false;
// 	if (Keyboard::isKeyPressed(m_right))
// 	{
// 		movement.x += PLAYER_SPEED;
// 		if (!checkCollision(boxesBoundings, movement)){
// 				isMoving = true;
// 				this->updateFolder(playerTextureFolder(isPlayerOne, RIGHT));
// 				this->getSprite().move(movement.x, 0);
// 			} else {
// 				this->resetAnimation(PLAYER_TEXTURE_RIGHT_DEFAULT_FRAME);
// 		}
// 			movement.x = 0;
// 	}
// 	if (Keyboard::isKeyPressed(m_left))
// 	{
// 		movement.x -= PLAYER_SPEED;
// 		if (!checkCollision(boxesBoundings, movement)) {
// 			isMoving = true;
// 			this->updateFolder(playerTextureFolder(isPlayerOne, LEFT));
// 			this->getSprite().move(movement.x, 0);
// 		} else {
// 			this->resetAnimation(PLAYER_TEXTURE_LEFT_DEFAULT_FRAME);
// 		}
// 		movement.x = 0;
// 	}
// 	if (Keyboard::isKeyPressed(m_up))
// 	{
// 		movement.y -= PLAYER_SPEED;
// 		if (!checkCollision(boxesBoundings, movement)) {
// 			isMoving = true;
// 			this->updateFolder(playerTextureFolder(isPlayerOne, UP));
// 			this->getSprite().move(0, movement.y);
// 		} else {
// 			this->resetAnimation(PLAYER_TEXTURE_UP_DEFAULT_FRAME);
// 		}
// 		movement.y = 0;
// 	}
// 	if (Keyboard::isKeyPressed(m_down))
// 	{
// 		movement.y += PLAYER_SPEED;
// 		if (!checkCollision(boxesBoundings, movement)) {
// 			isMoving = true;
// 			this->updateFolder(playerTextureFolder(isPlayerOne, DOWN));
// 			this->getSprite().move(0, movement.y);
// 		} else {
// 			this->resetAnimation(PLAYER_TEXTURE_DOWN_DEFAULT_FRAME);
// 		}
// 		movement.y = 0;
// 	}
// 	if (isMoving) updateAnimation();
// }

void Player::update(Level &level)
{
	Vector2f movement(0.f, 0.f);
	vector<FloatRect> boxesBoundings = getBoundingsFromEntities(level.getLevelBoxes());
	bool isMoving = false;

	auto handleMovement = [&](Keyboard::Key key, float dx, float dy, const std::string &folder, int defaultFrame)
	{
		if (Keyboard::isKeyPressed(key))
		{
			movement.x += dx;
			movement.y += dy;
			if (!checkCollision(boxesBoundings, movement))
			{
				isMoving = true;
				this->updateFolder(playerTextureFolder(isPlayerOne, folder));
				this->getSprite().move(movement.x, movement.y);
			}
			movement.x = 0;
			movement.y = 0;
		}
	};

	handleMovement(m_right, PLAYER_SPEED, 0.f, RIGHT, PLAYER_TEXTURE_RIGHT_DEFAULT_FRAME);
	handleMovement(m_left, -PLAYER_SPEED, 0.f, LEFT, PLAYER_TEXTURE_LEFT_DEFAULT_FRAME);
	handleMovement(m_up, 0.f, -PLAYER_SPEED, UP, PLAYER_TEXTURE_UP_DEFAULT_FRAME);
	handleMovement(m_down, 0.f, PLAYER_SPEED, DOWN, PLAYER_TEXTURE_DOWN_DEFAULT_FRAME);
	if (isMoving)
	{
		updateAnimation();
	} else {
		this->resetAnimation();
	}
}

void Player::draw(RenderWindow &w)
{
	w.draw(this->getSprite());
}

bool Player::canShoot()
{
	if (m_clock.getElapsedTime().asMilliseconds() < BOMB_LIFE_TIME)
		return false;
	if (!Keyboard::isKeyPressed(m_shoot))
		return false;
	m_clock.restart();
	return true;
}

Bomb *Player::shoot()
{
	char playerOrigin = isPlayerOne ? PLAYER_ONE_ID : PLAYER_TWO_ID;
	Bomb bomb(playerOrigin);
	return new Bomb(playerOrigin);
}

Vector2f Player::getDimensions() {
	int width = TILE_SIZE * PLAYER_SCALE_FACTOR;
	int height = TILE_SIZE * PLAYER_SCALE_FACTOR;
	
	return Vector2f(width, height);
}

Vector2f Player::getPosition()
{
	return this->getSprite().getPosition();
}

void Player::changePosition(Vector2f newPosition)
{
	this->getSprite().setPosition(newPosition);
}

bool Player::getIsPlayerOne() { return isPlayerOne; }
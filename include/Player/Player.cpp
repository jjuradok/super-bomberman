#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
#include <iostream>
#include "../config/ResourcesLocation/ResourcesLocation.h"
#include "../config/Constants.h"
#include "../utils/Boundings.h"

using namespace std;
using namespace sf;

Player::Player(bool isPlayerOne, Vector2f position, Clock &matchTime) : Animated(position, P1_TEXTURE_DOWN_FOLDER, PLAYER_ANIMATION_FRAMES), isPlayerOne(isPlayerOne), matchTime(matchTime)
{
	this->resetAnimation(PLAYER_TEXTURE_DOWN_DEFAULT_FRAME);
	if (!isPlayerOne) updateFolder(P2_TEXTURE_DOWN_FOLDER);

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
	// Como el jugador es más alto que los demás objetos, solo tomamos la parte inferior para las colisiones
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

void Player::update(Level &level)
{
	Vector2f movement(0.f, 0.f);
	vector<FloatRect> boxesBoundings = getBoundingsFromEntities(level.getLevelBoxes());
	bool isMoving = false;

	auto handleMovement = [&](Keyboard::Key key, float dx, float dy, const string &folder, int defaultFrame)
	{
		if (Keyboard::isKeyPressed(key))
		{
			// Calculamos la posición del jugador en el próximo frame, si no colisiona con ninguna caja se mueve
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

	// El proceso de "predecir" la posición en el próximo frame se hace para todas las direcciones
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
	if (m_clock.getElapsedTime().asMilliseconds() < BOMB_COOLDOWN && !isFirstShoot)
		return false;
	if (!Keyboard::isKeyPressed(m_shoot))
		return false;
	m_clock.restart();
	return true;
}

Bomb *Player::shoot()
{
	isFirstShoot = false;
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
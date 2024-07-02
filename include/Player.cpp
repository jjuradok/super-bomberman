#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
#include <iostream>
#include "config/Config.h"
#include "config/ResourcesLocation.h"
#include "config/Constants.h"

using namespace std;
using namespace sf;

FloatRect Player::getCollisionBounds()
{
	float collisionY = m_spr.getPosition().y + TILE_SIZE * PLAYER_SCALE_FACTOR - TILE_SIZE * PLAYER_SCALE_FACTOR / 2;
	FloatRect collisionRect = FloatRect(m_spr.getPosition().x, collisionY, TILE_SIZE * PLAYER_SCALE_FACTOR, TILE_SIZE * PLAYER_SCALE_FACTOR);
	return collisionRect;
}

bool Player::checkCollision(Level &level, Vector2f movement)
{
	FloatRect futureBounds = this->getCollisionBounds();
	futureBounds.left += movement.x;
	futureBounds.top += movement.y;

	vector<shared_ptr<Box>> levelBoxes = level.getLevelBoxes();
	for (auto &box : levelBoxes)
	{
		if (box->getGlobalBounds().intersects(futureBounds))
		{
			return true;
		}
	}
	return false;
}

Player::Player(bool isPrimary, Vector2f position)
{
	string textureSrc = isPrimary ? PLAYER_TEXTURE : SECOND_PLAYER_TEXTURE;
	m_tex.loadFromFile(textureSrc);
	m_spr.setTexture(m_tex);

	int textureWidth = PLAYER_TEXTURE_WIDTH;
	int textureHeight = PLAYER_TEXTURE_HEIGHT;
	int spriteWidth = TILE_SIZE;
	int spriteHeight = TILE_SIZE;

	m_spr.setTexture(m_tex);
	m_spr.setOrigin(0,0);

	m_spr.setScale(PLAYER_SCALE_FACTOR, PLAYER_SCALE_FACTOR);
	m_spr.setPosition(position);
	if (isPrimary)
	{
		m_right = Keyboard::D;
		m_left = Keyboard::A;
		m_up = Keyboard::W;
		m_down = Keyboard::S;
		m_shoot = Keyboard::Tab;
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

void Player::update(Level &level)
{
	Vector2f movement(0.f, 0.f);

	if (Keyboard::isKeyPressed(m_right))
	{
		movement.x += PLAYER_SPEED;
		if (!checkCollision(level, movement))
			m_spr.move(movement.x, 0);
			movement.x = 0;
	}
	if (Keyboard::isKeyPressed(m_left))
	{
		movement.x -= PLAYER_SPEED;
		if (!checkCollision(level, movement))
			m_spr.move(movement.x, 0);
			movement.x = 0;
	}
	if (Keyboard::isKeyPressed(m_up))
	{
		movement.y -= PLAYER_SPEED;
		if (!checkCollision(level, movement))
			m_spr.move(0, movement.y);
			movement.y = 0;
	}
	if (Keyboard::isKeyPressed(m_down))
	{
		movement.y += PLAYER_SPEED;
		if (!checkCollision(level, movement))
			m_spr.move(0, movement.y);
			movement.y = 0;

	}
}

void Player::draw(RenderWindow &w)
{
	w.draw(m_spr);
}

bool Player::canShoot()
{
	if (m_clock.getElapsedTime().asMilliseconds() < 500)
		return false;
	if (!Keyboard::isKeyPressed(m_shoot))
		return false;
	m_clock.restart();
	return true;
}

Bomb Player::generarDisparo()
{
	Vector2f p = m_spr.getPosition();
	float ang = m_spr.getRotation() * M_PI / 180;
	Vector2f d(cos(ang), sin(ang));
	return Bomb(p + 40.f * d, d);
}

Vector2f Player::getDimensions() {
	int width = TILE_SIZE * PLAYER_SCALE_FACTOR;
	int height = TILE_SIZE * PLAYER_SCALE_FACTOR;
	
	return Vector2f(width, height);
}

Vector2f Player::verPosicion()
{
	return m_spr.getPosition();
}

void Player::changePosition(Vector2f newPosition)
{
	m_spr.setPosition(newPosition);
}
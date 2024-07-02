#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Bomb.h"
#include "Level.h"

using namespace sf;

class Player
{
	bool isPrimary;
public:
	Player(bool isPrimary, Vector2f position);
	void update(Level &level);
	void draw(RenderWindow &w);
	bool canShoot();
	Bomb *shoot();
	Vector2f verPosicion();
	bool checkCollision(Level &level, Vector2f movement);
	FloatRect getCollisionBounds();
	Vector2f getDimensions();
	void changePosition(Vector2f newPosition);

private:
	Texture m_tex;
	Sprite m_spr;
	Keyboard::Key m_right, m_left, m_up, m_down, m_shoot;
	Clock m_clock;
};

#endif

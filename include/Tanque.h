#ifndef TANQUE_H
#define TANQUE_H

#include <SFML/Graphics.hpp>
#include "Disparo.h"
#include "Level.h"

using namespace sf;

class Tanque
{
	bool isPrimary;

public:
	Tanque(bool isPrimary);
	void update(Level &level);
	void draw(RenderWindow &w);
	bool canShoot();
	Disparo generarDisparo();
	Vector2f verPosicion();
	bool checkCollision(Level &level, Vector2f movement);
	FloatRect getCollisionBounds();

private:
	Texture m_tex;
	Sprite m_spr;
	Keyboard::Key m_right, m_left, m_up, m_down, m_shoot;
	Clock m_clock;
};

#endif

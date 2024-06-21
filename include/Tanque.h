#ifndef TANQUE_H
#define TANQUE_H

#include <SFML/Graphics.hpp>
#include "Disparo.h"

class Tanque
{
	bool isPrimary;
public:
	Tanque(bool isPrimary);
	void update();
	void draw(sf::RenderWindow &w);
	bool canShoot();
	Disparo generarDisparo();
	sf::Vector2f verPosicion();

private:
	sf::Texture m_tex;
	sf::Sprite m_spr;
	sf::Keyboard::Key m_right, m_left, m_up, m_down, m_shoot;
	sf::Clock m_clock;
};

#endif

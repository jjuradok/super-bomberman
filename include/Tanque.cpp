#include "Tanque.h"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
#include <iostream>
#include "Config.h"

using namespace std;
using namespace sf;

Tanque::Tanque(bool isPrimary)
{
	
	if (!m_tex.loadFromFile("assets/textures/player.png"))
	{
		cerr << "Error: No se pudo cargar el sprite sheet 'Sega Genesis 32X - Mega Bomberman - Bomberman.png'" << endl;
		return;
	}

	int spriteWidth = 16;
	int spriteHeight = 23;
	IntRect spriteRect;
	spriteRect = IntRect(72, 46, spriteWidth, spriteHeight); 

	m_spr.setTexture(m_tex);
	m_spr.setTextureRect(spriteRect); 
	
	float scaleFactor = 3.0f;					
	m_spr.setScale(scaleFactor, scaleFactor);
	if (isPrimary) {
		m_spr.setPosition(675, 430);
	} else {
		m_spr.setPosition(125, 430);
	}
	if (isPrimary) {
		m_right = Keyboard::D;
		m_left = Keyboard::A;
		m_up = Keyboard::W;
		m_down = Keyboard::S;
		m_shoot = Keyboard::Tab;
	} else {
		m_right = Keyboard::Right;
		m_left = Keyboard::Left;
		m_up = Keyboard::Up;
		m_down = Keyboard::Down;
		m_shoot = Keyboard::Space;
	}
	m_spr.setOrigin(spriteWidth / 2, spriteHeight / 2); 
}

void Tanque::update()
{
	if (Keyboard::isKeyPressed(m_right))
	{
		m_spr.move(3, 0);
	}
	if (Keyboard::isKeyPressed(m_left))
	{
		m_spr.move(-3, 0);
	}
	if (Keyboard::isKeyPressed(m_up))
	{
		m_spr.move(0, -3);
	}
	if (Keyboard::isKeyPressed(m_down))
	{
		m_spr.move(0, 3);
	}
}

void Tanque::draw(RenderWindow &w)
{
	w.draw(m_spr);
}

bool Tanque::canShoot()
{
	if (m_clock.getElapsedTime().asMilliseconds() < 500)
		return false;
	if (!Keyboard::isKeyPressed(m_shoot))
		return false;
	m_clock.restart();
	return true;
}

Disparo Tanque::generarDisparo()
{
	Vector2f p = m_spr.getPosition();
	float ang = m_spr.getRotation() * M_PI / 180;
	Vector2f d(cos(ang), sin(ang));
	return Disparo(p + 40.f * d, d);
}

Vector2f Tanque::verPosicion()
{
	return m_spr.getPosition();
}

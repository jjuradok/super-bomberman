#include "Tanque.h"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
using namespace std;
using namespace sf;

Tanque::Tanque(bool player_one)
{
	if (player_one)
		m_tex.loadFromFile("assets/textures/tanque1.png");
	else
		m_tex.loadFromFile("assets/textures/tanque2.png");
	m_spr.setTexture(m_tex);
	if (player_one)
	{
		m_spr.setPosition(175, 130);
		m_der = Keyboard::Right;
		m_izq = Keyboard::Left;
		m_acel = Keyboard::Up;
		m_fren = Keyboard::Down;
		m_disp = Keyboard::RShift;
	}
	else
	{
		m_spr.setPosition(675, 430);
		m_spr.setRotation(180);
		m_der = Keyboard::D;
		m_izq = Keyboard::A;
		m_acel = Keyboard::W;
		m_fren = Keyboard::S;
		m_disp = Keyboard::Tab;
	}
	m_spr.setOrigin(30, 25);
}

void Tanque::update()
{
	if (Keyboard::isKeyPressed(m_der))
		m_spr.rotate(2);
	if (Keyboard::isKeyPressed(m_izq))
		m_spr.rotate(-2);
	if (Keyboard::isKeyPressed(m_acel))
	{
		float ang = m_spr.getRotation() * M_PI / 180;
		m_spr.move(cos(ang), sin(ang));
	}
	if (Keyboard::isKeyPressed(m_fren))
	{
		float ang = m_spr.getRotation() * M_PI / 180;
		m_spr.move(-cos(ang), -sin(ang));
	}
}

void Tanque::draw(RenderWindow &w)
{
	w.draw(m_spr);
}

bool Tanque::debeDisparar()
{
	if (m_clock.getElapsedTime().asMilliseconds() < 500)
		return false;
	if (not Keyboard::isKeyPressed(m_disp))
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

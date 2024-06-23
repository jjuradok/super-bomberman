#include <iostream>
#include <cmath>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "Partida.h"
#include "Game.h"
#include "Ganador.h"
#include "Level.h"
#include "config/ResourcesLocation.h"

using namespace std;

Partida::Partida() : m_tanque_p1(true), m_tanque_p2(false), level(TEST_LEVEL_LAYOUT)
{
}

bool colisiona(Disparo &d, Tanque &t)
{
	Vector2f pd = d.verPosicion();
	Vector2f pt = t.verPosicion();
	Vector2f v = pd - pt;
	return sqrt(v.x * v.x + v.y * v.y) < 25;
}

bool fuera_de_la_pantalla(Disparo &d)
{
	Vector2f p = d.verPosicion();
	if (p.x < 0 or p.x > 800)
		return true;
	if (p.y < 0 or p.y > 600)
		return true;
	return false;
}

void Partida::update(Game &j)
{
	m_tanque_p1.update();
	if (m_tanque_p1.canShoot())
		m_disparos.push_back(m_tanque_p1.generarDisparo());
	auto it = remove_if(m_disparos.begin(), m_disparos.end(), fuera_de_la_pantalla);
	m_disparos.erase(it, m_disparos.end());
}

void Partida::draw(RenderWindow &w)
{
	w.clear(Color(220, 220, 180, 255));
	m_tanque_p1.draw(w);
	level.draw(w);
	for (Disparo &d : m_disparos)
		d.draw(w);
}

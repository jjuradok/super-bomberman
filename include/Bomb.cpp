#include "Bomb.h"

Bomb::Bomb(Vector2f pos, Vector2f dir) {
	m_circ.setPosition(pos);
	m_circ.setRadius(2);
	m_circ.setOrigin(2,2);
	m_circ.setFillColor(Color(0,0,0));
	m_vel = dir*3.f;
}

void Bomb::update ( ) {
	m_circ.move(m_vel);
}

void Bomb::draw(RenderWindow &w) {
	w.draw(m_circ);
}

Vector2f Bomb::verPosicion ( ) {
	return m_circ.getPosition();
}


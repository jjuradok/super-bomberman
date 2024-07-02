#ifndef BOMB_H
#define BOMB_H
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

class Bomb {
public:
	Bomb(Vector2f pos, Vector2f dir);
	void update();
	void draw(RenderWindow &w);
	Vector2f verPosicion();
private:
	CircleShape m_circ;
	Vector2f m_vel;
};

#endif


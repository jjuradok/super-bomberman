#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Bomb.h"
#include "Level.h"
#include "Animated.h"

using namespace sf;

class Player: public Animated
{
	bool isPlayerOne;
public:
	Player(bool isPlayerOne, Vector2f position);
	void update(Level &level);
	void draw(RenderWindow &w);
	bool canShoot();
	Bomb *shoot();
	Vector2f getPosition();
	bool checkCollision(vector <FloatRect> boundings, Vector2f movement);
	FloatRect getCollisionBounds();
	Vector2f getDimensions();
	void changePosition(Vector2f newPosition);
	bool getIsPlayerOne();	

private:
	Keyboard::Key m_right, m_left, m_up, m_down, m_shoot;
	Clock m_clock;
};

#endif

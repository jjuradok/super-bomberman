#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "../Bomb/Bomb.h"
#include "../Level/Level.h"
#include "../Animated/Animated.h"

using namespace sf;

class Player: public Animated
{
	bool isPlayerOne;
public:
	Player(bool isPlayerOne, Vector2f position, Clock &matchTime);
	Bomb *shoot();
	Vector2f getPosition();
	Vector2f getDimensions();
	FloatRect getCollisionBounds();
	bool canShoot();
	bool getIsPlayerOne();
	bool checkCollision(vector<FloatRect> boundings, Vector2f movement);
	void changePosition(Vector2f newPosition);
	void draw(RenderWindow &w);
	void update(Level &level);
private:
	Clock &matchTime;
	bool isFirstShoot = true;
	Keyboard::Key m_right, m_left, m_up, m_down, m_shoot;
	Clock m_clock;
};

#endif

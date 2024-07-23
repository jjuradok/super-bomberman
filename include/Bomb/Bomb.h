#ifndef BOMB_H
#define BOMB_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Animated/Animated.h"

using namespace sf;
using namespace std;

class Bomb: public Animated {
public:
	Bomb(char playerOrigin);
	void draw(RenderWindow &w);
	void changePosition(Vector2f newPosition);
	void setPaused(bool paused);
	bool shouldExplode();
	Vector2f getPosition();
private:
	char playerOrigin;
	Vector2f mVel;
	Clock bombClock;
	float timeRemaining = 3000.0f;
	bool isPaused;
};

#endif


#ifndef BOMB_H
#define BOMB_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;

class Bomb {
public:
	Bomb(char playerOrigin);
	void update();
	void draw(RenderWindow &w);
	void changePosition(Vector2f newPosition);
	bool shouldExplode();
	Vector2f getPosition();
private:
	char playerOrigin;
	Texture bombTexture;
	Sprite bombSprite;
	Vector2f mVel;
	Clock bombClock;
};

#endif


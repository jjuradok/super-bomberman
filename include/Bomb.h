#ifndef BOMB_H
#define BOMB_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;
using namespace std;

class Bomb {
public:
	bool shouldIncreaseFrame = true;
	int textureCurrentFrame = 0;
	Bomb(char playerOrigin);
	void update();
	void draw(RenderWindow &w);
	void changePosition(Vector2f newPosition);
	bool shouldExplode();
	Vector2f getPosition();
	Time getTextureTime();
private:
	char playerOrigin;
	string textureFolderPath;
	Texture bombTexture;
	Sprite bombSprite;
	Vector2f mVel;
	Clock bombClock, textureTime;
};

#endif


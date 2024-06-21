#ifndef ESCENA_H
#define ESCENA_H
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

class Game;

class Scene {
public:
	virtual void update(Game &j) = 0;
	virtual void draw(RenderWindow &) = 0;
};

#endif

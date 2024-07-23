#ifndef ESCENA_H
#define ESCENA_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include "../utils/LevelConfig.h"
using namespace sf;

class Game;

class Scene {
protected:
	Clock c_cont;
public:
	virtual void update(Game &j) = 0;
	virtual void draw(RenderWindow &) = 0;
	~Scene()=default;
};

#endif

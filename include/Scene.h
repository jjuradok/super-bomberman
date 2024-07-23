#ifndef ESCENA_H
#define ESCENA_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include "utils/LevelConfig.h"
using namespace sf;

class Game;

class Scene {
public:
	virtual void update(Game &j) = 0;
	virtual void draw(RenderWindow &) = 0;
	void updateTextColor(vector<LevelConfig> &levelsConfig, Game &j);
	void updateTextColor(std::vector<Text> &text, Game &j);
	void updateTextColor(Text &text, Game &j);
	virtual ~Scene()=default;
};

#endif

#ifndef ESCENA_H
#define ESCENA_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
using namespace sf;

class Game;

class Scene {
public:
	virtual void update(Game &j) = 0;
	virtual void draw(RenderWindow &) = 0;
	void updateTextColor(std::vector<sf::Text> &text, Game &j);
	void updateTextColor(Text &text, Game &j);
	~Scene()=default;
};

#endif

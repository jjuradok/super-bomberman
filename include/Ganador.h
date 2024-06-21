#ifndef GANADOR_H
#define GANADOR_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Scene.h"
using namespace sf;

class Ganador : public Scene
{
public:
	Ganador(bool player_one);
	void update(Game &j) override;
	void draw(RenderWindow &w) override;
private:
	Font m_font;
	Text m_text;
};

#endif


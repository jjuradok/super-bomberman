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
	Ganador(bool player_one,const std::string &lvl_played);
	void update(Game &j) override;
	void draw(RenderWindow &w) override;
	std::string get_lvl_played();
private:
	std::string m_lvl_played;
	Font m_font;
	Text m_text,m_replay,m_mm;
	std::vector<Text> m_options;
};

#endif


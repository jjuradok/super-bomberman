#ifndef GANADOR_H
#define GANADOR_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "../Scene/Scene.h"
using namespace sf;

class Winner : public Scene
{
public:
	Winner(bool player_one,const std::string &lvl_played);
	void update(Game &j) override;
	void draw(RenderWindow &w) override;
	std::string getLevelPlayed();
private:
	std::string m_lvl_played; //necesito esto para llamar al replay
	Font m_font;
	Text m_text,m_replay,m_mm;
	std::vector<Text> m_options;
};

#endif


#include "Ganador.h"
#include "Match.h"
#include "Game.h"
#include "LevelSelector.h"
#include "config/ResourcesLocation.h"
#include "Menu.h"

std::string Ganador::get_lvl_played() {
	return m_lvl_played;
}

Ganador::Ganador(bool player_one,const std::string &lvl_played): m_lvl_played(lvl_played)
{
	m_font.loadFromFile(FONT_FILE);

	m_text.setFont(m_font);
	m_text.setPosition(250, 250);
	m_text.setCharacterSize(100);
	m_replay.setFont(m_font);
	m_replay.setPosition(250, 750);
	m_replay.setCharacterSize(50);
	m_replay.setString("Replay");
	m_mm.setFont(m_font);
	m_mm.setPosition(750, 750);
	m_mm.setCharacterSize(50);
	m_mm.setString("Back!");
	m_options.push_back(m_replay); m_options.push_back(m_mm);
	if (player_one)
	{
		m_text.setString("Player One Wins!");
		m_text.setFillColor(Color(255, 128, 128));
	}
	else
	{
		m_text.setString("Player Two Wins!");
		m_text.setFillColor(Color(128, 255, 128));
	}
}

void Ganador::update(Game &j) {
	updateTextColor(m_options,j);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		if (m_replay.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(j.getWindow()).x), static_cast<float>(sf::Mouse::getPosition(j.getWindow()).y))) {
			j.changeScene(new Match(this->get_lvl_played()));
		}

		if (m_mm.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(j.getWindow()).x), static_cast<float>(sf::Mouse::getPosition(j.getWindow()).y))) {
			j.changeScene(new Menu);
		}
	}
}


void Ganador::draw(RenderWindow &w)
{
	w.clear(Color(0, 0, 0));
	w.draw(m_text);
	for (auto &text:m_options) {
		w.draw(text);
	}
}


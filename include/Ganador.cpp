#include "Ganador.h"
#include "Partida.h"
#include "Game.h"

Ganador::Ganador(bool player_one)
{
	m_font.loadFromFile("assets/fonts/asap.ttf");

	m_text.setFont(m_font);
	m_text.setPosition(250, 250);
	m_text.setCharacterSize(40);
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

void Ganador::update(Game &j)
{
	if (Keyboard::isKeyPressed(Keyboard::Return))
		j.changeScene(new Partida);
}

void Ganador::draw(RenderWindow &w)
{
	w.clear(Color(0, 0, 0));
	w.draw(m_text);
}

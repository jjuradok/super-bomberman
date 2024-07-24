#include "Game.h"
#include <SFML/Window/Event.hpp>
#include "../Settings/Settings.h"
#include <iostream>
#include "../Level/Level.h"
#include "../Match/Match.h"
#include "../Pause/Pause.h"

using namespace sf;
using namespace std;

Settings settings;

Game::Game(Scene *e)
		: m_win(VideoMode(settings.getScreenWidth(), settings.getScreenHeight()), "Bomberman"),
			m_esc(e), m_prox(nullptr), m_prev(nullptr)
{
	m_win.setFramerateLimit(60);
}

Scene *Game::getPreviousScene()
{
	return m_prev;
}

void Game::setPreviousScene(Scene *escena)
{
	m_prev = escena;
}

void Game::start()
{
	while (m_win.isOpen())
	{
		Event e;
		while (m_win.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				m_win.close();
			}
			if (e.type == Event::KeyPressed && e.key.code == Keyboard::Escape)
			{
				//dynamic_cast: "booleanizo" la escena actual para saber si es un Match
				auto matchScene = dynamic_cast<Match *>(m_esc);
				if (matchScene)
				{
					matchScene->setPaused(true);
					if (matchScene->isMatchPaused())
					{
						setPreviousScene(m_esc);
						changeScene(new Pause());
					}
					else
					{
						changeScene(m_prev);
						m_prev = nullptr; //dejo la escena previa nula
					}
				}
			}
		}

		m_win.clear();
		if (m_esc)
		{
			m_esc->update(*this);
			m_esc->draw(m_win);
		}
		m_win.display();

		if (m_prox)
		{

			if (m_esc != m_prev)
			{
				delete m_esc;
			}
			m_esc = m_prox;
			m_prox = nullptr;

			auto matchScene = dynamic_cast<Match *>(m_esc);
			if (matchScene) //si la escena actual es un Match, dejo la pausa en false
			{
				matchScene->setPaused(false);
			}
		}
	}
}

Game::~Game()
{
	delete m_esc;
}

void Game::changeScene(Scene *nueva_escena)
{
	m_prox = nueva_escena;
}

RenderWindow &Game::getWindow()
{
	return m_win;
}
#include "Game.h"
#include <SFML/Window/Event.hpp>
#include "config/Config.h"
#include "Settings.h"
#include <iostream>
#include <Level.h>

using namespace sf;
using namespace std;

std::string filename = SETTINGS_FILE;
Settings settings(filename);

Game::Game(Scene *e) : m_win(VideoMode(settings.getScreenWidth(), settings.getScreenHeight()), "Test")
{
	m_win.setFramerateLimit(60);
	m_esc = e;
}

void Game::start()
{
	while (m_win.isOpen())
	{
		Event e;
		while (m_win.pollEvent(e))
		{
			if (e.type == Event::Closed)
				m_win.close();
		}

		// cout << "Updating scene" << endl;
		m_esc->update(*this);

		// cout << "Drawing scene" << endl;
		m_esc->draw(m_win);
		m_win.display();

		if (m_prox)
		{
			cout << "Changing scene" << endl;
			delete m_esc;
			m_esc = m_prox;
			m_prox = nullptr;
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

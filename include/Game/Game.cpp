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
	  m_esc(e), m_prox(nullptr), m_prev(nullptr) {
	m_win.setFramerateLimit(60);
	std::cout << "Game initialized" << std::endl;
}

Scene* Game::getPreviousScene() {
	return m_prev;
}

void Game::setPreviousScene(Scene* escena) {
	m_prev = escena;
}

void Game::start() {
	std::cout << "Game started" << std::endl;
	while (m_win.isOpen()) {
		sf::Event e;
		while (m_win.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				m_win.close();
			}

			if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape) {
				auto matchScene = dynamic_cast<Match*>(m_esc);
				if (matchScene) {
					std::cout << "Toggling pause" << std::endl;
					matchScene->setPaused(true);
					if (matchScene->isMatchPaused()) {
						// Guardar la escena actual y cambiar a la pausa
						setPreviousScene(m_esc);
						changeScene(new Pause());
					} else {
						// Volver a la escena anterior
						changeScene(m_prev);
						m_prev = nullptr;
					}
				}
			}
		}

		m_win.clear();
		if (m_esc) {
			m_esc->update(*this);
			m_esc->draw(m_win);
		} else {
			std::cout << "Current scene is null" << std::endl;
		}
		m_win.display();

		if (m_prox) {
			std::cout << "Changing scene" << std::endl;
			// Eliminar la escena actual
			if (m_esc != m_prev) {
				delete m_esc;
			}
			m_esc = m_prox;
			m_prox = nullptr;

			// Asegurarse de que la escena Match no esté en pausa
			auto matchScene = dynamic_cast<Match*>(m_esc);
			if (matchScene) {
				matchScene->setPaused(false);
			}
		}
	}
	std::cout << "Window closed" << std::endl;
}

Game::~Game() {
	std::cout << "Game destructor called" << std::endl;
	delete m_esc;
}

void Game::changeScene(Scene *nueva_escena) {
	std::cout << "Scene change requested" << std::endl;
	m_prox = nueva_escena;
}

sf::RenderWindow& Game::getWindow() {
	return m_win;
}
#ifndef GAME_H
#define GAME_H
#include "Scene.h"
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

class Game {
public:
	Game(Scene *e);
	void changeScene(Scene *nueva_escena);
	void setPreviousScene(Scene *escena);
	void start();
	Scene *getPreviousScene();
	RenderWindow &getWindow();
	~Game();

private:
	RenderWindow m_win;
	Scene *m_esc,*m_prox, *m_prev;
};

#endif

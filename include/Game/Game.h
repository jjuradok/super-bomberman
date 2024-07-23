#ifndef GAME_H
#define GAME_H
#include "../Scene/Scene.h"
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

class Game {
public:
	Game(Scene *e);
	void start();
	void changeScene(Scene *nueva_escena);
	~Game();
	RenderWindow &getWindow();
	void setPreviousScene(Scene* escena);
	Scene* getPreviousScene();
private:
	RenderWindow m_win;
	Scene *m_esc,*m_prox, *m_prev;
};

#endif

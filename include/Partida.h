#ifndef PARTIDA_H
#define PARTIDA_H

#include "Disparo.h"
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene.h"
#include "Level.h"
#include "Tanque.h"

using namespace sf;
using namespace std;

class Partida : public Scene
{
	vector<vector<char>> matrix;
	Tanque m_tanque_p1;
	Tanque m_tanque_p2;
	Level level;
	vector<Disparo> m_disparos;
	void loadMatrix(string fileName);
public:
	Partida();
	void update(Game &j) override;
	void draw(RenderWindow &w) override;
};

#endif

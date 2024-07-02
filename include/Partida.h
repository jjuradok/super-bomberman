#ifndef PARTIDA_H
#define PARTIDA_H

#include "Disparo.h"
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene.h"
#include "Level.h"
#include "Player.h"

using namespace sf;
using namespace std;

class Partida : public Scene
{
	vector<vector<char>> matrix;
	Player player_1;
	Player player_2;
	Level level;
	vector<Disparo> m_disparos;
	void loadMatrix(string fileName);
public:
	Partida();
	void update(Game &j) override;
	void draw(RenderWindow &w) override;
};

#endif

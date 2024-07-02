#ifndef MATCH_H
#define MATCH_H

#include "Bomb.h"
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Scene.h"
#include "Level.h"
#include "Player.h"

using namespace sf;
using namespace std;

class Match : public Scene
{
	vector<vector<char>> matrix;
	Player player_1;
	Player player_2;
	Level level;
	vector<Bomb*> bombs;
	void loadMatrix(string fileName);
public:
	Match();
	void update(Game &j) override;
	void draw(RenderWindow &w) override;
};

#endif

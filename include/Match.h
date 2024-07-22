#ifndef MATCH_H
#define MATCH_H

#include "Bomb.h"
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio.hpp>
#include "Scene.h"
#include "Level.h"
#include "Player.h"
#include "Explosion.h"

using namespace sf;
using namespace std;

class Match : public Scene
{
	vector<vector<char>> matrix;
	Player player_1;
	Player player_2;
	Level level;
	vector<Bomb*> bombs;
	vector<Explosion*> explosions;
	void loadMatrix(string fileName);
	void removeBomb(Bomb *bomb);
	vector<vector<char>> updateMatrixAfterExplosion(MatrixPosition bombPosition, Game &game);
	string lvl_loaded;
	bool isPaused;

public:
	Match(const string &lvl_name);
	string get_lvl_loaded();
	void update(Game &j) override;
	void draw(RenderWindow &w) override;
	void setPaused(bool paused);
	bool isMatchPaused();
};

#endif

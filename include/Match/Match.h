#ifndef MATCH_H
#define MATCH_H

#include "../Bomb/Bomb.h"
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio.hpp>
#include "../Scene/Scene.h"
#include "../Level/Level.h"
#include "../Player/Player.h"
#include "../Explosion/Explosion.h"

using namespace sf;
using namespace std;

class Match : public Scene
{
	string lvl_loaded;
	vector<vector<char>> matrix;
	vector<Bomb *> bombs;
	vector<Explosion *> explosions;
	Player player_1;
	Player player_2;
	Level level;
	Clock matchTime;
	bool isPaused;

	vector<vector<char>> updateMatrixAfterExplosion(MatrixPosition bombPosition, Game &game);
	void loadMatrix(string fileName);
	void removeBomb(Bomb *bomb);
	void handleEndMatch(Game &game, Player *winner);
public:
	Match(const string &levelId);
	string getLevelId();
	bool isMatchPaused();
	bool withinBounds(int i, int j, int rows, int columns);
	void handleMatchMusic(bool stop = false);
	void update(Game &j) override;
	void draw(RenderWindow &w) override;
	void setPaused(bool paused);
};

#endif

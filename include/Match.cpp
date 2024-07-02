#include <iostream>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Match.h"
#include "Game.h"
#include "Ganador.h"
#include "Level.h"
#include "config/ResourcesLocation.h"
#include "config/Config.h"
#include "config/Constants.h"
#include "utils/Vector.h"
#include "utils/MatrixPosition.h"
#include "ScreenPosition.h"

using namespace std;

Match::Match() : player_1(true, Vector2f(-100, -100)), player_2(false, Vector2f(-100, -100))
{
	loadMatrix(TEST_LEVEL_LAYOUT);
	level = Level(matrix);
	MatrixPosition player1Position = level.findPosition(PLAYER_ONE_ID);
	MatrixPosition player2Position = level.findPosition(PLAYER_TWO_ID);
	float size = TILE_SIZE * SCALE_FACTOR;

	Vector2f player1PositionPixels = getPositionCenteredIntoLevel(Vector2f(player1Position.j * size + 4, player1Position.i * size), level.getDimensions(), player_1.getDimensions());
	Vector2f player2PositionPixels = getPositionCenteredIntoLevel(Vector2f(player2Position.j * size + 4, player2Position.i * size), level.getDimensions(), player_2.getDimensions());

	player_1.changePosition(player1PositionPixels);
	player_2.changePosition(player2PositionPixels);
}

bool colisiona(Bomb &d, Player &t)
{
	Vector2f pd = d.verPosicion();
	Vector2f pt = t.verPosicion();
	Vector2f v = pd - pt;
	return sqrt(v.x * v.x + v.y * v.y) < 25;
}

void Match::update(Game &j)
{
	player_1.update(level);
	player_2.update(level);
	if (player_1.canShoot()) {
		Bomb *shotBomb = player_1.shoot();
		float size = TILE_SIZE * SCALE_FACTOR;
		MatrixPosition bombPositionInMatrix = parsePixelsIntoMatrixPosition(player_1.verPosicion(), level.getDimensions(), Vector2f(size, size));
		Vector2f bombAdjustedPosition = parseMatrixPositionIntoPixels(bombPositionInMatrix, level.getDimensions(), Vector2f(size, size));
		shotBomb->changePosition(bombAdjustedPosition);
		bombs.push_back(shotBomb);
	}
	if (player_2.canShoot()) {
		Bomb *shotBomb = player_2.shoot();
		float size = TILE_SIZE * SCALE_FACTOR;
		MatrixPosition bombPositionInMatrix = parsePixelsIntoMatrixPosition(player_2.verPosicion(), level.getDimensions(), Vector2f(size, size));
		Vector2f bombAdjustedPosition = parseMatrixPositionIntoPixels(bombPositionInMatrix, level.getDimensions(), Vector2f(size, size));
		shotBomb->changePosition(bombAdjustedPosition);
		bombs.push_back(shotBomb);
	}
}

void Match::draw(RenderWindow &w)
{
	w.clear(Color(220, 220, 180, 255));
	level.draw(w);
	player_1.draw(w);
	player_2.draw(w);
	for (Bomb *d : bombs)
		d->draw(w);
}

void Match::loadMatrix(string fileName)
{
	ifstream file(fileName);
	if (!file.is_open())
	{
		cerr << "Error: No se pudo abrir el archivo " << fileName << endl;
		return;
	}

	string line;
	while (getline(file, line))
	{
		istringstream iss(line);
		vector<char> row;
		char character;

		while (iss >> character)
		{
			row.push_back(character);
		}
		matrix.push_back(row);
	}
	file.close();

}
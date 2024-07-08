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

//TODO: refactorizar esta funcion
vector<vector<char>> Match::updateMatrixAfterExplosion(MatrixPosition bombPosition, Game &game)
{
	vector<vector<char>> updatedMatrix = matrix;
	int rows = matrix.size();
	int columns = matrix[0].size();
	vector <Player *> players = { &player_1, &player_2 };

	vector<char> bombRow = matrix[bombPosition.i];
	vector<char> bombColumn(rows);
	MatrixPosition explosionPosition, playerPosition;

			for (int i = 0; i < rows; ++i)
	{
		bombColumn[i] = matrix[i][bombPosition.j];
	}

	for (int j = bombPosition.j; j < columns; ++j)
	{
		explosionPosition = MatrixPosition({bombPosition.i,j});

		for (Player *player : players)
		{
			playerPosition = parsePixelsIntoMatrixPosition(player->getPosition(), level.getDimensions(), player->getDimensions());
			if (playerPosition == explosionPosition)
			{
				game.changeScene(new Ganador(!player->getIsPlayerOne()));
			}
		}
		if (bombRow[j] == SOLID_TILE)
			break;
		if (bombRow[j] == DESTRUCTIBLE_TILE)
		{
			bombRow[j] = EMPTY_TILE;
			break;
		}
	}
	
	for (int j = bombPosition.j; j >= 0; --j)
	{
		explosionPosition = MatrixPosition({bombPosition.i, j});
		for (Player *player : players)
		{
			playerPosition = parsePixelsIntoMatrixPosition(player->getPosition(), level.getDimensions(), player->getDimensions());
			if (playerPosition == explosionPosition)
			{
				game.changeScene(new Ganador(!player->getIsPlayerOne()));
			}
		}
		if (bombRow[j] == SOLID_TILE)
			break;
		if (bombRow[j] == DESTRUCTIBLE_TILE)
		{
			bombRow[j] = EMPTY_TILE;
			break;
		}
	}
	
	for (int i = bombPosition.i; i < rows; ++i)
	{
		explosionPosition = MatrixPosition({i, bombPosition.j});
		for (Player *player : players)
		{
			playerPosition = parsePixelsIntoMatrixPosition(player->getPosition(), level.getDimensions(), player->getDimensions());
			if (playerPosition == explosionPosition)
			{
				game.changeScene(new Ganador(!player->getIsPlayerOne()));
			}
		}
		if (bombColumn[i] == SOLID_TILE)
			break;
		if (bombColumn[i] == DESTRUCTIBLE_TILE)
		{
			bombColumn[i] = EMPTY_TILE;
			break;
		}
	}
	
	for (int i = bombPosition.i; i >= 0; --i)
	{
		explosionPosition = MatrixPosition({i, bombPosition.j});
		for (Player *player : players)
		{
			playerPosition = parsePixelsIntoMatrixPosition(player->getPosition(), level.getDimensions(), player->getDimensions());
			if (playerPosition == explosionPosition)
			{
				game.changeScene(new Ganador(!player->getIsPlayerOne()));
			}
		}
		if (bombColumn[i] == SOLID_TILE)
			break;
		if (bombColumn[i] == DESTRUCTIBLE_TILE)
		{
			bombColumn[i] = EMPTY_TILE;
			break;
		}
	}

	// Reemplazo la fila y columna en la matriz actualizada
	updatedMatrix[bombPosition.i] = bombRow;
	for (int i = 0; i < rows; ++i)
	{
		updatedMatrix[i][bombPosition.j] = bombColumn[i];
	}
	return updatedMatrix;
}

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


void Match::update(Game &j) {
	player_1.update(level);
	player_2.update(level);
	float size = TILE_SIZE * SCALE_FACTOR;

	for (Bomb *bomb : bombs)
	{
		if (bomb->shouldExplode())
		{
			MatrixPosition bombPositionInMatrix = parsePixelsIntoMatrixPosition(bomb->getPosition(), level.getDimensions());
			vector<vector<char>> updatedMatrix = updateMatrixAfterExplosion(bombPositionInMatrix, j);
			matrix = updatedMatrix;
			level.update(updatedMatrix);

			removeBomb(bomb);
		}
	}
	
	vector<Player *> playersToShoot;
	if (player_1.canShoot())
		playersToShoot.push_back(&player_1);
	if (player_2.canShoot())
		playersToShoot.push_back(&player_2);
		
	for (Player *player : playersToShoot) {
		Bomb *shotBomb = player->shoot();
		Vector2f playerCenterPosition = Vector2f(player->getPosition().x + size / 2, player->getPosition().y + size / 2);
		MatrixPosition bombPositionInMatrix = parsePixelsIntoMatrixPosition(playerCenterPosition, level.getDimensions());
		Vector2f bombAdjustedPosition = parseMatrixPositionIntoPixels(bombPositionInMatrix, level.getDimensions());
		shotBomb->changePosition(bombAdjustedPosition);
		bombs.push_back(shotBomb);
	}
}

void Match::removeBomb(Bomb *bomb) {
	delete bomb;
	bombs.erase(remove(bombs.begin(), bombs.end(), bomb), bombs.end());
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
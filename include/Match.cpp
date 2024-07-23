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
#include "utils/Boundings.h"

using namespace std;

vector<vector<char>> Match::updateMatrixAfterExplosion(MatrixPosition bombPosition, Game &game)
{
	vector<vector<char>> updatedMatrix = matrix;
	vector<Player *> players = {&player_1, &player_2};
	int rows = matrix.size();
	int columns = matrix[0].size();

	// Recorro la fila y "reviso" tile por tile
	for (int j = bombPosition.j; j < columns; j++)
	{
		if (abs(bombPosition.j - j) > BOMB_MAX_RANGE)
			break;
		if (!withinBounds(bombPosition.i, j, rows, columns))
			break;
		char &tile = updatedMatrix[bombPosition.i][j];
		Vector2f pos = parseMatrixPositionIntoPixels({bombPosition.i, j}, level.getDimensions());

		if (tile == SOLID_TILE)
			break;
		if (tile == DESTRUCTIBLE_TILE)
		{
			Explosion *explosion = new Explosion(pos);
			explosions.push_back(explosion);
			tile = EMPTY_TILE;
			break;
		}
		if (!includes(COLLISION_TILES, tile))
		{
			Explosion *explosion = new Explosion(pos);
			explosions.push_back(explosion);
		}
	}

	for (int j = bombPosition.j; j >= 0; j--)
	{
		if (abs(bombPosition.j - j) > BOMB_MAX_RANGE)
			break;
		if (!withinBounds(bombPosition.i, j, rows, columns))
			break;
		char &tile = updatedMatrix[bombPosition.i][j];
		Vector2f pos = parseMatrixPositionIntoPixels({bombPosition.i, j}, level.getDimensions());

		if (tile == SOLID_TILE)
			break;
		if (tile == DESTRUCTIBLE_TILE)
		{
			Explosion *explosion = new Explosion(pos);
			explosions.push_back(explosion);
			tile = EMPTY_TILE;
			break;
		}
		if (!includes(COLLISION_TILES, tile))
		{
			Explosion *explosion = new Explosion(pos);
			explosions.push_back(explosion);
		}
	}

	// Recorro la columna y "reviso" tile por tile
	for (int i = bombPosition.i; i < rows; i++)
	{
		if (abs(bombPosition.i - i) > BOMB_MAX_RANGE)
			break;
		if (!withinBounds(i, bombPosition.j, rows, columns))
			break;
		char &tile = updatedMatrix[i][bombPosition.j];
		Vector2f pos = parseMatrixPositionIntoPixels({i, bombPosition.j}, level.getDimensions());

		if (tile == SOLID_TILE)
			break;
		if (tile == DESTRUCTIBLE_TILE)
		{
			Explosion *explosion = new Explosion(pos);
			explosions.push_back(explosion);
			tile = EMPTY_TILE;
			break;
		}
		if (!includes(COLLISION_TILES, tile))
		{
			Explosion *explosion = new Explosion(pos);
			explosions.push_back(explosion);
		}
	}

	for (int i = bombPosition.i; i >= 0; i--)
	{
		if (abs(bombPosition.i - i) > BOMB_MAX_RANGE)
			break;
		if (!withinBounds(i, bombPosition.j, rows, columns))
			break;
		char &tile = updatedMatrix[i][bombPosition.j];
		Vector2f pos = parseMatrixPositionIntoPixels({i, bombPosition.j}, level.getDimensions());

		if (tile == SOLID_TILE)
			break;
		if (tile == DESTRUCTIBLE_TILE)
		{
			Explosion *explosion = new Explosion(pos);
			explosions.push_back(explosion);
			tile = EMPTY_TILE;
			break;
		}
		if (!includes(COLLISION_TILES, tile))
		{
			Explosion *explosion = new Explosion(pos);
			explosions.push_back(explosion);
		}
	}

	return updatedMatrix;
}

bool Match::withinBounds(int i, int j, int rows, int columns)
{
	return i >= 0 && i < rows && j >= 0 && j < columns;
}

void Match::handleEndMatch(Game &game, Player *winner)
{
	handleMatchMusic(true);
	game.changeScene(new Ganador(!winner->getIsPlayerOne(), this->getLevelId()));
}

string Match::getLevelId()
{
	return lvl_loaded;
}

Match::Match(const string &levelId)
		: player_1(true, Vector2f(-100, -100), matchTime),
			player_2(false, Vector2f(-100, -100), matchTime),
			lvl_loaded(levelId),
			level(levelId),
			isPaused(false)
{
	matchTime.restart();
	loadMatrix("resources/levels/" + levelId + ".txt");
	level.loadMatrix(matrix);
	MatrixPosition player1Position = level.findPosition(PLAYER_ONE_ID);
	MatrixPosition player2Position = level.findPosition(PLAYER_TWO_ID);
	float size = TILE_SIZE * SCALE_FACTOR;

	Vector2f player1PositionPixels = getPositionCenteredIntoLevel(Vector2f(player1Position.j * size + 4, player1Position.i * size), level.getDimensions(), player_1.getDimensions());
	Vector2f player2PositionPixels = getPositionCenteredIntoLevel(Vector2f(player2Position.j * size + 4, player2Position.i * size), level.getDimensions(), player_2.getDimensions());

	if (player1Position != INVALID_MATRIX_POSITION)
		player_1.changePosition(player1PositionPixels);
	if (player2Position != INVALID_MATRIX_POSITION)
		player_2.changePosition(player2PositionPixels);
}

void Match::handleMatchMusic(bool stop)
{
	SoundSource::Status musicStatus = level.getLevelResources()->getBackgroundMusic()->getStatus();
	if (stop)
	{
		level.getLevelResources()->getBackgroundMusic()->stop();
		return;
	}
	if (isPaused)
	{
		level.getLevelResources()->getBackgroundMusic()->pause();
		SoundSource::Status musicStatus = level.getLevelResources()->getBackgroundMusic()->getStatus();
		return;
	}
	if (musicStatus == SoundSource::Status::Paused)
	{
		level.getLevelResources()->getBackgroundMusic()->play();
		return;
	}
}

void Match::update(Game &j)
{
	handleMatchMusic();
	if (isPaused)
		return;
	player_1.update(level);
	player_2.update(level);
	float size = TILE_SIZE * SCALE_FACTOR;
	vector<Player *> players = {&player_1, &player_2};

	for (Player *player : players)
	{
		for (Explosion *explosion : explosions)
		{
			explosion->updateAnimation();
			if (explosion->getGlobalBounds().intersects(player->getCollisionBounds()))
			{
				handleEndMatch(j, player);
			}
		}
	}

	for (Bomb *bomb : bombs)
	{
		bomb->updateAnimation();
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

	for (Player *player : playersToShoot)
	{
		Bomb *shotBomb = player->shoot();
		Vector2f playerCenterPosition = Vector2f(player->getPosition().x + size / 2, player->getPosition().y + size / 2);
		MatrixPosition bombPositionInMatrix = parsePixelsIntoMatrixPosition(playerCenterPosition, level.getDimensions());
		Vector2f bombAdjustedPosition = parseMatrixPositionIntoPixels(bombPositionInMatrix, level.getDimensions());
		shotBomb->changePosition(bombAdjustedPosition);
		bombs.push_back(shotBomb);
	}
}

void Match::removeBomb(Bomb *bomb)
{
	delete bomb;
	bombs.erase(remove(bombs.begin(), bombs.end(), bomb), bombs.end());
}

void Match::draw(RenderWindow &w)
{
	w.clear(Color(level.getLevelResources()->getBackgroundColor()));
	level.draw(w);
	player_1.draw(w);
	player_2.draw(w);
	for (Bomb *d : bombs)
		d->draw(w);
	for (auto explosion = explosions.begin(); explosion != explosions.end();)
	{
		(*explosion)->draw(w);
		if ((*explosion)->shouldRemove())
		{
			delete *explosion;
			explosion = explosions.erase(explosion);
		}
		else
		{
			++explosion;
		}
	}
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
bool Match::isMatchPaused()
{
	return isPaused;
}
void Match::setPaused(bool paused)
{
	isPaused = paused;
	for (Bomb *bomb : bombs)
	{
		bomb->setPaused(paused);
	}
}

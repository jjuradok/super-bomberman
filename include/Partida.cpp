#include <iostream>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Partida.h"
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

Partida::Partida() : m_tanque_p1(true, Vector2f(-100, -100)), m_tanque_p2(false, Vector2f(-100, -100))
{
	loadMatrix(TEST_LEVEL_LAYOUT);
	level = Level(matrix);
	MatrixPosition player1Position = level.findPosition(PLAYER_ONE_ID);
	MatrixPosition player2Position = level.findPosition(PLAYER_TWO_ID);
	float size = TILE_SIZE * SCALE_FACTOR;

	Vector2f player1PositionPixels = getPositionCenteredIntoLevel(Vector2f(player1Position.j * size + 4, player1Position.i * size), level.getDimensions(), m_tanque_p1.getDimensions());
	Vector2f player2PositionPixels = getPositionCenteredIntoLevel(Vector2f(player2Position.j * size + 4, player2Position.i * size), level.getDimensions(), m_tanque_p2.getDimensions());

	m_tanque_p1.changePosition(player1PositionPixels);
	m_tanque_p2.changePosition(player2PositionPixels);
}

bool colisiona(Disparo &d, Tanque &t)
{
	Vector2f pd = d.verPosicion();
	Vector2f pt = t.verPosicion();
	Vector2f v = pd - pt;
	return sqrt(v.x * v.x + v.y * v.y) < 25;
}

bool fuera_de_la_pantalla(Disparo &d)
{
	Vector2f p = d.verPosicion();
	if (p.x < 0 or p.x > 800)
		return true;
	if (p.y < 0 or p.y > 600)
		return true;
	return false;
}

void Partida::update(Game &j)
{
	m_tanque_p1.update(level);
	m_tanque_p2.update(level);
	if (m_tanque_p1.canShoot())
		m_disparos.push_back(m_tanque_p1.generarDisparo());
	if (m_tanque_p2.canShoot())
		m_disparos.push_back(m_tanque_p2.generarDisparo());
	auto it = remove_if(m_disparos.begin(), m_disparos.end(), fuera_de_la_pantalla);
m_disparos.erase(it, m_disparos.end());
}

void Partida::draw(RenderWindow &w)
{
	w.clear(Color(220, 220, 180, 255));
	level.draw(w);
	m_tanque_p1.draw(w);
	m_tanque_p2.draw(w);
	for (Disparo &d : m_disparos)
		d.draw(w);
}

void Partida::loadMatrix(string fileName)
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
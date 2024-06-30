#include "Level.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "Box.h"
#include "config/Config.h"

using namespace std;

void Level::loadMatrix()
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
    vector<int> row;
    int number;

    while (iss >> number)
    {
      row.push_back(number);
    }
    matrix.push_back(row);
  }
  file.close();

  int rows = matrix.size();
  int columns = matrix[0].size();
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      if (matrix[i][j] == 1 || matrix[i][j] == 2)
      {
        bool isDestructible = matrix[i][j] == 2;
        auto box = make_shared<Box>(isDestructible);
        Vector2f boxPosition(j * 48, i * 48);
        box->setPosition(boxPosition);
        boxes.push_back(box);
      }
    }
  }
}

vector<vector<int>> Level::getMatrix() const
{
  return matrix;
}

int Level::getRows() const
{
  return matrix.size();
}

int Level::getColumns() const
{
  return matrix[0].size();
}

Level::Level(string filename) : fileName(filename)
{
  loadMatrix();
}

void Level::draw(sf::RenderWindow &w)
{
  for (auto &box : boxes)
  {
    box->draw(w);
  }
}

int Level::getTile(int x, int y) const
{
  return matrix[y][x];
}

vector<shared_ptr<Box>> Level::getLevelBoxes()
{
  return boxes;
}
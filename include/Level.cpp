#include "Level.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "Box.h"
#include "config/Config.h"
#include "config/Constants.h"
#include "utils/Vector.h"
#include "ScreenPosition.h"

using namespace std;

vector<vector<char>> Level::getMatrix() const
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

Level::Level(vector<vector<char>> matrix) : matrix(matrix)
{
  int rows = matrix.size();
  int columns = matrix[0].size();
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      if (includes(COLLISION_TILES, matrix[i][j]))
      {
        bool isDestructible = matrix[i][j] == DESTRUCTIBLE;
        int boxSize = TILE_SIZE * SCALE_FACTOR;
        Vector2f levelSize(columns * boxSize, rows * boxSize);
        Vector2f boxPosition(j * boxSize, i * boxSize);
        Vector2f pos = getPositionCenteredIntoLevel(boxPosition, levelSize, Vector2f(boxSize, boxSize));
        auto box = make_shared<Box>(isDestructible, pos);
        boxes.push_back(box);
      }
    }
  }
}

Level::Level() {}

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

MatrixPosition Level::findPosition(char tile) 
{
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix[i].size(); j++)
    {
      if (matrix[i][j] == tile)
      {
        return MatrixPosition({i, j});
      }
    }
  }
}

Vector2f Level::getDimensions() {
  int width = this->getColumns() * TILE_SIZE * SCALE_FACTOR;
  int height = this->getRows() * TILE_SIZE * SCALE_FACTOR;
  
  return Vector2f(width, height);
}

vector<shared_ptr<Box>> Level::getLevelBoxes()
{
  return boxes;
}
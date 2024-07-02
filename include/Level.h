#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "Box.h"
#include "utils/MatrixPosition.h"

using namespace std;
using namespace sf;
class Level
{
  int rows, columns;
  vector<shared_ptr<Box>> boxes;
  string fileName;
  vector<vector<char>> matrix;
public:
  Level(vector<vector<char>> matrix);
  Level();
  int getRows() const;
  int getColumns() const;
  int getTile(int x, int y) const;
  vector<vector<char>> getMatrix() const;
  vector<shared_ptr<Box>> getLevelBoxes();
  MatrixPosition findPosition(char tile);
  Vector2f getDimensions();
  void draw(RenderWindow &w);
};

#endif // LEVEL_H

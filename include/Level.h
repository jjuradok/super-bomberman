#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "Box.h"
#include "utils/MatrixPosition.h"
#include "LevelResources.h"

using namespace std;
using namespace sf;
class Level
{
  int rows, columns;
  string lvl_loaded;
  vector<Box *> boxes;
  string fileName;
  vector<vector<char>> matrix;
  LevelResources levelResources;
  Box *handleCreateBox(MatrixPosition position, string levelId);
public:
  Level(const string &lvl_name);
  int getRows() const;
  int getColumns() const;
  int getTile(int x, int y) const;
  vector<vector<char>> getMatrix() const;
  vector<Box *> getLevelBoxes();
  MatrixPosition findPosition(char tile);
  Vector2f getDimensions();
  void loadMatrix(vector<vector<char>> matrix);
  void loadLevel(const string &lvl_name);
  void draw(RenderWindow &w);
  void update(vector<vector<char>> matrix);
  LevelResources getLevelResources();
};

#endif // LEVEL_H

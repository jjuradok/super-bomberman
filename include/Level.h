#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include "Box.h"

using namespace std;

class Level
{
  int rows, columns;
  vector<shared_ptr<Box>> boxes;
  string fileName;
  vector<vector<int>> matrix;
  void loadMatrix();
public:
  Level(string filename);
  int getRows() const;
  int getColumns() const;
  int getTile(int x, int y) const;
  vector<vector<int>> getMatrix() const;
  vector<shared_ptr<Box>> getLevelBoxes();
  void draw(sf::RenderWindow &w);
};

#endif // LEVEL_H

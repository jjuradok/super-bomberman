#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class Level
{
  string fileName;
  vector<vector<int>> matrix;
  void loadMatrix();

public:
  Level(string filename);
  int getRows();
  int getColumns();
  vector<vector<int>> getMatrix();
  void draw(sf::RenderWindow &w);
};

#endif 

#include <SFML/Graphics.hpp>

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "Level.h"
#include "Box.h"
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
}

vector<vector<int>> Level::getMatrix()
{
  return matrix;
}

Level::Level(string filename) {
  fileName = filename;
  loadMatrix();
}

void Level::draw(sf::RenderWindow &w)
{
  int rows = matrix.size();
  int columns = matrix[0].size();
    for (int i = 0; i < rows; i++)
    {
      Box testBox(true);

      for (int j = 0; j < columns; j++)
      {
        if (matrix[i][j] == 1)
        {
          Box box(false);
          box.setPosition(j * 48, i * 48);
          box.draw(w);
        }
        else if (matrix[i][j] == 2)
        {
          Box box(true);
          box.setPosition(j * 48, i * 48);
          box.draw(w);
        }
      }
    }
}
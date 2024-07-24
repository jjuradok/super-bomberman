#include "Level.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "SFML/Audio/SoundSource.hpp"

#include "../Box/Box.h"
#include "../config/Constants.h"
#include "../utils/Vector.h"
#include "../utils/Vector.h"
#include "../ScreenPosition/ScreenPosition.h"
#include "../LevelResources/LevelResources.h"

using namespace std;
using namespace sf;

Level::Level(const string &lvl_name) : levelResources(lvl_name), lvl_loaded(lvl_name)
{
  levelResources.getBackgroundMusic()->play();
};

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

void Level::loadMatrix(vector<vector<char>> matrix) {
  matrix = matrix;
  update(matrix);
}

Box *Level::handleCreateBox(MatrixPosition position, string levelId)
{
  int i = position.i;
  int j = position.j;
  int boxSize = TILE_SIZE * SCALE_FACTOR;

  bool isDestructible = matrix[i][j] == DESTRUCTIBLE_TILE;
  bool isBorder = includes(BORDER_TILES, matrix[i][j]);

  Vector2f boxPosition(j * boxSize, i * boxSize);
  Vector2f positionCentered = getPositionCenteredIntoLevel(boxPosition, this->getDimensions(), Vector2f(boxSize, boxSize));
  Vector2f pos = Vector2f(positionCentered.x + boxSize / 2, positionCentered.y + boxSize / 2);

  // Por defecto, creamos una caja "interior", si está en el borde aplicamos una logica particular
  Box *box = new Box(isDestructible, pos, &levelResources);

  if (isBorder)
  {
    // Se detecta si es una esquina en base a la posición en la matriz o bien porque el tile lo explicita
    bool isCorner = (i == 0 && j == 0) || (i == 0 && j == columns - 1) || (i == rows - 1 && j == 0) || (i == rows - 1 && j == columns - 1) || includes(CORNER_TILES, matrix[i][j]);

    bool isRightBorder = j == columns - 1;
    bool isTopBorder = i == 0;
    bool isBottomBorder = i == rows - 1;

    Texture boxTexture = isCorner ? levelResources.getCornerBoxTexture() : levelResources.getBorderBoxTexture();
    delete box;

    // Creamos la caja con textura de borde/esquina y la rotamos si es necesario
    box = new Box(boxTexture, pos);
    // Borde derecho
    if ((isRightBorder && !isCorner) || matrix[i][j] == BORDER_RIGHT)
    {
      box->setScale(Vector2f(-SCALE_FACTOR, SCALE_FACTOR));
    }
    // Borde de arriba
    if ((isTopBorder && !isCorner) || matrix[i][j] == BORDER_TOP)
    {
      box->setRotation(90);
    }
    // Borde de abajo
    if ((isBottomBorder && !isCorner) || matrix[i][j] == BORDER_BOTTOM)
    {
      box->setRotation(-90);
    }
    // Esquina S.D
    if ((isCorner && isRightBorder && isTopBorder) || matrix[i][j] == CORNER_TOP_RIGHT)
    {
      box->setScale(Vector2f(-SCALE_FACTOR, SCALE_FACTOR));
      box->setRotation(-90);
    }
    // Esqiona I.D
    if ((isCorner && isRightBorder && isBottomBorder) || matrix[i][j] == CORNER_BOTTOM_RIGHT)
    {
      box->setScale(Vector2f(-SCALE_FACTOR, SCALE_FACTOR));
    }
    // Esquina I.I
    if ((isCorner && !isRightBorder && isTopBorder) || matrix[i][j] == CORNER_TOP_LEFT)
    {
      box->setRotation(90);
    }
    
  }
  return box;
}

void Level::update(vector<vector<char>> newMatrix)
{
  boxes.clear();
  this->matrix = newMatrix;
  rows = matrix.size();
  columns = matrix[0].size();

  // Recorro la matriz para crear las cajas
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      if (includes(COLLISION_TILES, matrix[i][j]))
      {
        MatrixPosition position = {i, j};
        Box *box = handleCreateBox(position, lvl_loaded);
        if (box != nullptr)
        {
          boxes.push_back(box);
        } 
      }
    }
  }
}

void Level::draw(RenderWindow &w)
{
  float scale = max(w.getSize().x / levelResources.getBackgroundTexture().getSize().x, w.getSize().y / levelResources.getBackgroundTexture().getSize().y);
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      Vector2f position = getPositionCenteredIntoLevel(Vector2f(j * TILE_SIZE * SCALE_FACTOR, i * TILE_SIZE * SCALE_FACTOR), this->getDimensions(), Vector2f(TILE_SIZE * SCALE_FACTOR, TILE_SIZE * SCALE_FACTOR));
      levelResources.getGroundSprite().setPosition(position);
      
      // Dibujo el suelo centrado en pantalla
      w.draw(levelResources.getGroundSprite());
    }
  }

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
  return INVALID_MATRIX_POSITION;
}

Vector2f Level::getDimensions() {
  int width = this->getColumns() * TILE_SIZE * SCALE_FACTOR;
  int height = this->getRows() * TILE_SIZE * SCALE_FACTOR;
  
  return Vector2f(width, height);
}

vector<Box *> Level::getLevelBoxes()
{
  return boxes;
}

LevelResources *Level::getLevelResources()
{
  return &levelResources;
}

Level::~Level()
{
  levelResources.getBackgroundMusic()->stop();
  for (auto &box : boxes)
  {
    delete box;
  }
}
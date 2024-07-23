#include "Level.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "Box.h"
#include "config/Config.h"
#include "config/Constants.h"
#include "utils/Vector.h"
#include "ScreenPosition.h"
#include "LevelResources.h"
#include "SFML/Audio/SoundSource.hpp"

using namespace std;
using namespace sf;

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

Level::Level(const string &lvl_name) : levelResources(lvl_name), lvl_loaded(lvl_name){
  levelResources.getBackgroundMusic()->play();
};

Box *Level::handleCreateBox(MatrixPosition position, string levelId)
{
  int i = position.i;
  int j = position.j;
  bool isDestructible = matrix[i][j] == DESTRUCTIBLE;
  bool isBorder = matrix[i][j] == BORDER;

  int boxSize = TILE_SIZE * SCALE_FACTOR;
  Vector2f boxPosition(j * boxSize, i * boxSize);
  Vector2f positionCentered = getPositionCenteredIntoLevel(boxPosition, this->getDimensions(), Vector2f(boxSize, boxSize));
  Vector2f pos = Vector2f(positionCentered.x + boxSize / 2, positionCentered.y + boxSize / 2);
  Box *box = new Box(isDestructible, pos, &levelResources);

  if (isBorder)
  {
    bool isCorner = (i == 0 && j == 0) || (i == 0 && j == columns - 1) || (i == rows - 1 && j == 0) || (i == rows - 1 && j == columns - 1);
    bool isRightBorder = j == columns - 1;
    bool isTopBorder = i == 0;
    bool isBottomBorder = i == rows - 1;
    Texture boxTexture = isCorner ? levelResources.getCornerBoxTexture() : levelResources.getBorderBoxTexture();
    delete box;
    box = new Box(boxTexture, pos);
    if (isRightBorder && !isCorner)
    {
      box->setScale(Vector2f(-SCALE_FACTOR, SCALE_FACTOR));
    }
    if (isTopBorder && !isCorner)
    {
      box->setRotation(90);
    }
    if (isBottomBorder && !isCorner)
    {
      box->setRotation(-90);
    }
    if (isCorner && isRightBorder && isTopBorder)
    {
      box->setScale(Vector2f(-SCALE_FACTOR, SCALE_FACTOR));
      box->setRotation(-90);
    }
    if (isCorner && isRightBorder && isBottomBorder)
    {
      box->setScale(Vector2f(-SCALE_FACTOR, SCALE_FACTOR));
    }
    if (isCorner && !isRightBorder && isTopBorder)
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
  // levelResources.getBackgroundSprite().setScale(5, 5);
  // w.draw(levelResources.getBackgroundSprite());
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      Vector2f position = getPositionCenteredIntoLevel(Vector2f(j * TILE_SIZE * SCALE_FACTOR, i * TILE_SIZE * SCALE_FACTOR), this->getDimensions(), Vector2f(TILE_SIZE * SCALE_FACTOR, TILE_SIZE * SCALE_FACTOR));
      levelResources.getGroundSprite().setPosition(position);
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
}
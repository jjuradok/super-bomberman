#include <iostream>
#include "ScreenPosition.h"
#include "config/Config.h"
#include "Settings.h"
#include "utils/MatrixPosition.h"

using namespace sf;

Vector2f getPositionCenteredIntoLevel(const Vector2f &position, const Vector2f &levelSize, const Vector2f &tileSize)
{
  Settings settings;
  unsigned int screen_width = settings.getScreenWidth();
  unsigned int screen_height = settings.getScreenHeight();

  float x = (screen_width - levelSize.x) / 2 + position.x ;
  float y = (screen_height - levelSize.y) / 2 + position.y;

  return Vector2f(x, y);
}

Vector2f parseMatrixPositionIntoPixels(MatrixPosition position, Vector2f levelSize, Vector2f tileSize) {
  int posX = position.j * tileSize.x;
  int posY = position.i * tileSize.y ;
  Vector2f positionCentered = getPositionCenteredIntoLevel(Vector2f(posX,posY), levelSize, tileSize);
  
  return positionCentered;
}

MatrixPosition parsePixelsIntoMatrixPosition(Vector2f position, Vector2f levelSize, Vector2f tileSize) {
  Settings settings;
  unsigned int screen_width = settings.getScreenWidth();
  unsigned int screen_height = settings.getScreenHeight();

  float xMatrix = position.x - (screen_width - levelSize.x) / 2;
  float yMatrix = position.y - (screen_height - levelSize.y) / 2;

  int i = yMatrix / tileSize.y;
  int j = xMatrix / tileSize.x;

  return MatrixPosition({i, j});
}
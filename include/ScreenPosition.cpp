#include "ScreenPosition.h"
#include "config/Config.h"
#include "Settings.h"
#include <iostream>

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
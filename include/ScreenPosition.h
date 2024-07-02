#ifndef SCREEN_POSITION_H
#define SCREEN_POSITION_H

#include <SFML/Graphics.hpp>
#include "utils/MatrixPosition.h"

using namespace sf;

Vector2f getPositionCenteredIntoLevel(const Vector2f &position, const Vector2f &levelSize, const Vector2f &tileSize);
Vector2f parseMatrixPositionIntoPixels(MatrixPosition position, Vector2f levelSize, Vector2f tileSize);

#endif

#ifndef SCREEN_POSITION_H
#define SCREEN_POSITION_H

#include <SFML/Graphics.hpp>
#include "../utils/MatrixPosition.h"
#include "../config/Config.h"

using namespace sf;

const Vector2f defaultSize(TILE_SIZE *SCALE_FACTOR, TILE_SIZE *SCALE_FACTOR);

Vector2f getPositionCenteredIntoLevel(const Vector2f &position, const Vector2f &levelSize, const Vector2f &tileSize = defaultSize);
Vector2f parseMatrixPositionIntoPixels(MatrixPosition position, Vector2f levelSize, Vector2f tileSize = defaultSize);
MatrixPosition parsePixelsIntoMatrixPosition(Vector2f position, Vector2f levelSize, Vector2f tileSize = defaultSize);

#endif

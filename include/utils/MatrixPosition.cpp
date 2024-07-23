#include "MatrixPosition.h"

bool operator==(const MatrixPosition &a, const MatrixPosition &b) {
  return a.i == b.i && a.j == b.j;
}

bool operator!=(const MatrixPosition &a, const MatrixPosition &b) {
  return !(a == b);
}

const MatrixPosition INVALID_MATRIX_POSITION = {-1, -1};
#include "MatrixPosition.h"

bool operator==(const MatrixPosition &a, const MatrixPosition &b) {
  return a.i == b.i && a.j == b.j;
}
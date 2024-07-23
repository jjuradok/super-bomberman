#ifndef MATRIX_POSITION_H
#define MATRIX_POSITION_H

struct MatrixPosition
{
  int i, j;
};

extern const MatrixPosition INVALID_MATRIX_POSITION;

bool operator==(const MatrixPosition &a, const MatrixPosition &b);
bool operator!=(const MatrixPosition &a, const MatrixPosition &b);

#endif
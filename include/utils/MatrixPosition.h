#ifndef MATRIX_POSITION_H
#define MATRIX_POSITION_H

struct MatrixPosition
{
  int i, j;
};

bool operator==(const MatrixPosition &a, const MatrixPosition &b);

#endif
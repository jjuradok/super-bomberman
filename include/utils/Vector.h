#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
using namespace std;

template <typename T>

bool includes(vector<T> v, T value) {
  for (T i = 0; i < v.size(); i++) {
    if (v[i] == value) {
      return true;
    }
  }
  return false;
}

#endif
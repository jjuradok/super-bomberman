#ifndef BOUNDINGS_H
#define BOUNDINGS_H

#include <vector>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

template <typename T>
vector<FloatRect> getBoundingsFromEntities(const vector<T *> &entities);

#include "Boundings.inl"

#endif

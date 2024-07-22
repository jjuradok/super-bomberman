#ifndef BOUNDINGS_INL
#define BOUNDINGS_INL

#include "Boundings.h"

using namespace sf;
using namespace std;

template <typename T>
vector<FloatRect> getBoundingsFromEntities(const vector<T *> &entities)
{
  vector<FloatRect> boundings;
  for (T *entity : entities)
  {
    boundings.push_back(entity->getGlobalBounds());
  }
  return boundings;
}

#endif

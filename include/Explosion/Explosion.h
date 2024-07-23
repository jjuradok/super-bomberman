#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <SFML/Graphics.hpp>
#include "../Animated/Animated.h"

using namespace sf;

class Explosion: public Animated {
  Clock explosionTime;
public:
  Explosion(Vector2f position);
  Vector2f getPosition();
  FloatRect getGlobalBounds();
  Time getElapsedTime();
  bool shouldRemove();
  void draw(RenderWindow &w);
};

#endif
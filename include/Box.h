#ifndef BOX_H
#define BOX_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "LevelResources.h"

using namespace sf;
using namespace std;

class Box {
  Vector2f position;
  Texture m_tex;
  Sprite m_spr;
  bool isDestructible;
  public:
    Box(bool isDestructible, Vector2f position, LevelResources *levelResources);
    Box(Texture &texture, Vector2f position);
    bool getIsDestructible();
    void update();
    void draw(RenderWindow &w);
    void setPosition(Vector2f pos);
    void setRotation(float angle);
    void setScale(Vector2f scale);
    Vector2f getPosition();
    Vector2f getDimensions();
    FloatRect getGlobalBounds();
};

#endif 
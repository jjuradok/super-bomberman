#ifndef BOX_H
#define BOX_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Box {
  Vector2f position;
  Texture m_tex;
  Sprite m_spr;
  bool isDestructible;
  public:
    Box(bool isDestructible, Vector2f position);
    bool getIsDestructible();
    void update();
    void draw(RenderWindow &w);
    void setPosition(Vector2f pos);
    Vector2f getPosition();
    Vector2f getDimensions();
    FloatRect getGlobalBounds();
};

#endif 
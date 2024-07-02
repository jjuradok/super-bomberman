#ifndef BOX_H
#define BOX_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Box {
  Vector2f position;
  sf::Texture m_tex;
  sf::Sprite m_spr;
  bool isDestructible;
  public:
    Box(bool isDestructible, Vector2f position);
    bool getIsDestructible();
    void update();
    void draw(sf::RenderWindow &w);
    void setPosition(Vector2f pos);
    Vector2f getPosition();
    Vector2f getDimensions();
    FloatRect getGlobalBounds();
};

#endif 
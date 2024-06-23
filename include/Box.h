#include <SFML/Graphics.hpp>

class Box {
  int xPos, yPos;
  sf::Texture m_tex;
  sf::Sprite m_spr;
  bool isDestructible;
  public:
  Box(bool isDestructible);
  bool getIsDestructible();
  void update();
  void draw(sf::RenderWindow &w);
  void setPosition(int x, int y);
};
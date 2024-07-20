#include <SFML/Graphics.hpp>

using namespace sf;

class Explosion {
  bool shouldIncreaseFrame = true;
  int  textureCurrentFrame = 0;
  Texture texture;
  Sprite sprite;
  Clock explosionTime, textureTime;

public:
  Explosion(Vector2f position);
  Vector2f getPosition();
  FloatRect getGlobalBounds();
  Time getElapsedTime();
  Time getTextureTime();
  void update();
  bool shouldRemove();
  void draw(RenderWindow &w);
};
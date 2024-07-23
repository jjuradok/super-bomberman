#include "Explosion.h"
#include "../config/ResourcesLocation.h"
#include "../config/Config.h"
#include "../config/Constants.h"

Explosion::Explosion(Vector2f position) : Animated(position,EXPLOSION_TEXTURES_FOLDER, EXPLOSION_ANIMATION_FRAMES)
{
  explosionTime.restart();
}

Time Explosion::getElapsedTime() {
  return explosionTime.getElapsedTime();
}

void Explosion::draw(RenderWindow &w) {
  w.draw(this->getSprite());
}

Vector2f Explosion::getPosition()
{
  return this->getSprite().getPosition();
}

bool Explosion::shouldRemove() {
  return explosionTime.getElapsedTime().asMilliseconds() >= EXPLOSION_LIFE_TIME;
}

FloatRect Explosion::getGlobalBounds() {
  return this->getSprite().getGlobalBounds();
}

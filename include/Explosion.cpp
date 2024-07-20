#include "Explosion.h"
#include "config/ResourcesLocation.h"
#include "config/Config.h"

Explosion::Explosion(Vector2f position) {
  string texturesFolder = (EXPLOSION_TEXTURES_FOLDER);
  string texturePath = texturesFolder + to_string(textureCurrentFrame) + ".png";
  texture.loadFromFile(texturePath);
  sprite.setTexture(texture);
  sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);
  sprite.setPosition(position);
  explosionTime.restart();
}

Time Explosion::getElapsedTime() {
  return explosionTime.getElapsedTime();
}

void Explosion::draw(RenderWindow &w) {
  w.draw(sprite);
}

Vector2f Explosion::getPosition()
{
  return sprite.getPosition();
}

bool Explosion::shouldRemove() {
  return explosionTime.getElapsedTime().asMilliseconds() >= EXPLOSION_LIFE_TIME;
}

FloatRect Explosion::getGlobalBounds() {
  return sprite.getGlobalBounds();
}

void Explosion::update() {
  if (textureTime.getElapsedTime().asMilliseconds() >= ANIMATION_FRAME_DURATION) {
    if (shouldIncreaseFrame) {
      textureCurrentFrame++;
    } else {
      textureCurrentFrame--;
    }
    if (textureCurrentFrame == EXPLOSION_ANIMATION_FRAMES - 1) {
      shouldIncreaseFrame = false;
    }
    if (textureCurrentFrame == 0) {
      shouldIncreaseFrame = true;
    }
    string texturesFolder = (EXPLOSION_TEXTURES_FOLDER);
    string texturePath = texturesFolder + to_string(textureCurrentFrame) + ".png";
    texture.loadFromFile(texturePath);
    sprite.setTexture(texture);
    textureTime.restart();
    
  }
}
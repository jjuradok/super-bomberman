#include <iostream>
#include <SFML/Graphics.hpp>
#include "Box.h"
#include "config/ResourcesLocation.h"
#include "config/Config.h"
#include "ScreenPosition.h"
#include "LevelResources.h"

using namespace std;
using namespace sf;

Box::Box(bool isDestructible, Vector2f position, LevelResources *levelResources) : isDestructible(isDestructible), position(position)
{
  m_tex = isDestructible ? levelResources->getDestructibleBoxTexture() : levelResources->getIndestructibleBoxTexture();
  m_spr.setTexture(m_tex);
  m_spr.setScale(SCALE_FACTOR, SCALE_FACTOR);
  m_spr.setPosition(position);
  m_spr.setOrigin(TILE_SIZE / 2, TILE_SIZE / 2);
  
}

Box::Box(Texture &texture, Vector2f position) {
  m_tex = texture;
  m_spr.setTexture(m_tex);
  m_spr.setScale(SCALE_FACTOR, SCALE_FACTOR);
  m_spr.setPosition(position);
  m_spr.setOrigin(TILE_SIZE / 2, TILE_SIZE / 2);
  
}

void Box::draw(RenderWindow &w)
{
  w.draw(m_spr);  
}

void Box::setPosition(Vector2f pos)
{
  position = pos;
  m_spr.setPosition(pos);
}

Vector2f Box::getPosition()
{
  return position;
}

FloatRect Box::getGlobalBounds() {
  return m_spr.getGlobalBounds();
}

bool Box::getIsDestructible()
{
  return isDestructible;
}

Vector2f Box::getDimensions() {
  float boxSize = TILE_SIZE * SCALE_FACTOR;
  
  return Vector2f(boxSize, boxSize);
}

void Box::setRotation(float angle) {
  m_spr.setRotation(angle);
}

void Box::setScale(Vector2f scale) {
  m_spr.setScale(scale);
}
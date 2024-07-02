#include <iostream>
#include <SFML/Graphics.hpp>
#include "Box.h"
#include "config/ResourcesLocation.h"
#include "config/Config.h"
#include "ScreenPosition.h"

using namespace std;

Box::Box(bool isDestructible, Vector2f position) : isDestructible(isDestructible), position(position)
{
  string texSrc = isDestructible ? DESTRUCTIBLE_BOX_TEXTURE : INDESTRUCTIBLE_BOX_TEXTURE ;
  m_tex.loadFromFile(texSrc);
  m_spr.setTexture(m_tex);
  m_spr.setPosition(position);
  m_spr.setScale(SCALE_FACTOR, SCALE_FACTOR);
}

void Box::draw(sf::RenderWindow &w)
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
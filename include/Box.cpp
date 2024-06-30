#include <SFML/Graphics.hpp>
#include "Box.h"
#include "config/ResourcesLocation.h"
#include "config/Config.h"
#include <iostream>

using namespace std;

Box::Box(bool isDestructible): isDestructible(isDestructible) {
  string texSrc = isDestructible ? DESTRUCTIBLE_BOX_TEXTURE : INDESTRUCTIBLE_BOX_TEXTURE ;
  m_tex.loadFromFile(texSrc);
  m_spr.setTexture(m_tex);
}

void Box::draw(sf::RenderWindow &w)
{
  m_spr.setScale(SCALE_FACTOR, SCALE_FACTOR);
  setPosition(position);
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
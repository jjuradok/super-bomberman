#include <SFML/Graphics.hpp>
#include "Box.h"
#include "config/ResourcesLocation.h"
using namespace std;

Box::Box(bool isDestructible): isDestructible(isDestructible) {
  string texSrc = isDestructible ? DESTRUCTIBLE_BOX_TEXTURE : INDESTRUCTIBLE_BOX_TEXTURE ;
  m_tex.loadFromFile(texSrc);
  m_spr.setTexture(m_tex);
}

void Box::draw(sf::RenderWindow &w)
{
  m_spr.setScale(3.0f, 3.0f);
  setPosition(xPos, yPos);
  w.draw(m_spr);  
}

void Box::setPosition(int x, int y)
{
  xPos = x;
  yPos = y;
  m_spr.setPosition(xPos, yPos);
}

bool Box::getIsDestructible()
{
  return isDestructible;
}
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Animated.h"
#include "config/Config.h"

using namespace sf;
using namespace std;

string getTexturePath(string textureFolderPath, int textureCurrentFrame)
{
  return textureFolderPath + to_string(abs(textureCurrentFrame)) + ".png";
}

Animated::Animated(Vector2f position, string textureFolderPath, int totalFrames): textureFolderPath(textureFolderPath), totalFrames(totalFrames) {
  string texturePath = getTexturePath(textureFolderPath, textureCurrentFrame);
  texture.loadFromFile(texturePath);
  sprite.setTexture(texture);
  sprite.setPosition(position);
  sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);
}

Time Animated::getAnimationFrameTime(){
  return textureTime.getElapsedTime();
};
string Animated::getTextureFolderPath(){
  return textureFolderPath;
};
Sprite &Animated::getSprite(){
  return sprite;
};
Texture &Animated::getTexture(){
  return texture;
};
bool Animated::getShouldIncreaseFrame(){
  return shouldIncreaseFrame;
};
int Animated::getTextureCurrentFrame(){
  return textureCurrentFrame;
};

void Animated::updateAnimation()
{
  if (textureTime.getElapsedTime().asMilliseconds() >= animationFrameDuration)
  {
    if (shouldIncreaseFrame)
    {
      textureCurrentFrame++;
    }
    else
    {
      textureCurrentFrame--;
    }
    if (textureCurrentFrame == totalFrames - 1)
    {
      shouldIncreaseFrame = false;
    }
    if (textureCurrentFrame == 0)
    {
      shouldIncreaseFrame = true;
    }
    string texturePath = getTexturePath(textureFolderPath, textureCurrentFrame);
    texture.loadFromFile(texturePath);
    sprite.setTexture(texture);
    textureTime.restart();
  }
}
void Animated::updateFolder(string textureFolderPath) {
  this->textureFolderPath = textureFolderPath;
  string texturePath = getTexturePath(textureFolderPath, textureCurrentFrame);
  texture.loadFromFile(texturePath);
  sprite.setTexture(texture);
}

void Animated::updateTotalFrames(int totalFrames) {
  totalFrames = totalFrames;
}

void Animated::resetAnimation(int frame)
{
  string texturePath = getTexturePath(textureFolderPath, frame);
  texture.loadFromFile(texturePath);
  sprite.setTexture(texture);
}

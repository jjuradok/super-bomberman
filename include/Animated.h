#ifndef ANIMATED_H
#define ANIMATED_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "config/Config.h"
using namespace sf;
using namespace std;

class Animated
{
public:
  Animated(Vector2f position, string textureFolderPath, int totalFrames);
  Time getAnimationFrameTime();
  string getTextureFolderPath();
  Sprite &getSprite();
  Texture &getTexture();
  bool getShouldIncreaseFrame();
  int getTextureCurrentFrame();
  virtual void update();
  void updateFolder(string textureFolderPath);
  void updateTotalFrames(int totalFrames);
private:
  bool shouldIncreaseFrame = true;
  int textureCurrentFrame = 0, totalFrames;
  float animationFrameDuration = ANIMATION_FRAME_DURATION;
  string textureFolderPath;
  Texture texture;
  Sprite sprite;
  Clock textureTime;
};

#endif

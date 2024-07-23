#ifndef ANIMATED_H
#define ANIMATED_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../config/Constants.h"
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
  void updateAnimation();
  void updateFolder(string textureFolderPath);
  void updateTotalFrames(int totalFrames);
  void resetAnimation(int frame = 1);
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

#ifndef LEVELRESOURCES_H
#define LEVELRESOURCES_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class LevelResources {
  string levelId;
  Texture groundTexture,backgroundTexture ,destructibleBoxTexture, indestructibleBoxTexture, borderBoxTexture, cornerBoxTexture;
  Sprite groundSprite;
  Color backgroundColor;
  Music backgroundMusic;
public:
  LevelResources(string levelId);
  Color getBackgroundColor();
  Texture& getGroundTexture();
  Texture& getDestructibleBoxTexture();
  Texture& getIndestructibleBoxTexture();
  Texture& getBorderBoxTexture();
  Texture& getCornerBoxTexture();
  Texture& getBackgroundTexture();
  Sprite& getGroundSprite();
  Music* getBackgroundMusic();
  ~LevelResources();
};

#endif
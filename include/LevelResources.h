#ifndef LEVELRESOURCES_H
#define LEVELRESOURCES_H

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class LevelResources {
  string levelId;
  Texture groundTexture,backgroundTexture ,destructibleBoxTexture, indestructibleBoxTexture, borderBoxTexture, cornerBoxTexture;
  public: 
  LevelResources(string levelId);
  Texture& getGroundTexture();
  Texture& getDestructibleBoxTexture();
  Texture& getIndestructibleBoxTexture();
  Texture& getBorderBoxTexture();
  Texture& getCornerBoxTexture();
  Texture& getBackgroundTexture();
};

#endif
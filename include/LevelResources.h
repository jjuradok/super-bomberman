#ifndef LEVELRESOURCES_H
#define LEVELRESOURCES_H

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class LevelResources {
  string levelId;
  Texture groundTexture, destructibleBoxTexture, indestructibleBoxTexture, borderBoxTexture, cornerBoxTexture, explosionTexture;
  public: 
  LevelResources(string levelId);
  Texture& getGroundTexture();
  Texture& getDestructibleBoxTexture();
  Texture& getIndestructibleBoxTexture();
  Texture& getBorderBoxTexture();
  Texture& getCornerBoxTexture();
  Texture& getExplosionTexture();
};

#endif
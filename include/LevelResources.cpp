#include <iostream>

#include "LevelResources.h"
#include "config/ResourcesLocation.h"
using namespace std;

    LevelResources::LevelResources(string levelId) : levelId(levelId)
{
  string assetsInitialPath = levelAssetsFolder(levelId);
  string destructibleBoxPath = assetsInitialPath + DESTRUCTIBLE_BOX_LEVEL_TEXTURE;
  string indestructibleBoxPath = assetsInitialPath + INDESTRUCTIBLE_BOX_LEVEL_TEXTURE;
  string borderBoxPath = assetsInitialPath + BORDER_BOX_LEVEL_TEXTURE;
  string cornerBoxPath = assetsInitialPath + CORNER_BOX_LEVEL_TEXTURE;
  string bottomBorderBoxPath = assetsInitialPath + BOTTOM_BORDER_BOX_LEVEL_TEXTURE;
  string groundPath = assetsInitialPath + GROUND_LEVEL_TEXTURE;
  string backgroundPath = assetsInitialPath + BACKGROUND_LEVEL_TEXTURE;

  groundTexture.loadFromFile(groundPath);
  backgroundTexture.loadFromFile(backgroundPath);
  destructibleBoxTexture.loadFromFile(destructibleBoxPath);
  indestructibleBoxTexture.loadFromFile(indestructibleBoxPath);
  borderBoxTexture.loadFromFile(borderBoxPath);
  cornerBoxTexture.loadFromFile(cornerBoxPath);
};

Texture &LevelResources::getGroundTexture()
{
  return groundTexture;
}

Texture &LevelResources::getDestructibleBoxTexture()
{
  return destructibleBoxTexture;
}

Texture &LevelResources::getIndestructibleBoxTexture()
{
  return indestructibleBoxTexture;
}

Texture &LevelResources::getBorderBoxTexture()
{
  return borderBoxTexture;
}

Texture &LevelResources::getCornerBoxTexture()
{
  return cornerBoxTexture;
}

Texture &LevelResources::getBackgroundTexture()
{
  return backgroundTexture;
}
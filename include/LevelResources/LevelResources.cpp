#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "LevelResources.h"
#include "../config/ResourcesLocation/ResourcesLocation.h"
#include "../config/Constants.h"

using namespace std;

string getAssetPath(string levelId, string assetName)
{
  return levelAssetsFolder(levelId) + assetName;
}

LevelResources::LevelResources(string levelId) : levelId(levelId)
{
  string destructibleBoxPath = getAssetPath(levelId, DESTRUCTIBLE_BOX_LEVEL_TEXTURE);
  string indestructibleBoxPath = getAssetPath(levelId, INDESTRUCTIBLE_BOX_LEVEL_TEXTURE);
  string borderBoxPath = getAssetPath(levelId, BORDER_BOX_LEVEL_TEXTURE);
  string cornerBoxPath = getAssetPath(levelId, CORNER_BOX_LEVEL_TEXTURE);
  string bottomBorderBoxPath = getAssetPath(levelId, BOTTOM_BORDER_BOX_LEVEL_TEXTURE);
  string groundPath = getAssetPath(levelId, GROUND_LEVEL_TEXTURE);

  groundTexture.loadFromFile(groundPath);
  destructibleBoxTexture.loadFromFile(destructibleBoxPath);
  indestructibleBoxTexture.loadFromFile(indestructibleBoxPath);
  borderBoxTexture.loadFromFile(borderBoxPath);
  cornerBoxTexture.loadFromFile(cornerBoxPath);
  backgroundMusic.setLoop(true);
  backgroundMusic.openFromFile(getAssetPath(levelId, LEVEL_BACKGROUND_MUSIC));

  groundSprite.setTexture(groundTexture);
  groundSprite.setScale(SCALE_FACTOR, SCALE_FACTOR);

  string fileLocation = levelAssetsFolder(levelId) + BACKGROUND_COLOR_FILE;
  ifstream file(fileLocation);
  string line;
  while (getline(file, line))
  {

    vector<string> parts;
    istringstream words(line);
    string word;

    while (getline(words, word, ','))
    {
      parts.push_back(word);
    }

    if (parts.size() >= 4)
    {
      int r = stoi(parts[0]);
      int g = stoi(parts[1]);
      int b = stoi(parts[2]);
      int a = stoi(parts[3]);

      backgroundColor = Color(r, g, b, a);
    }
  }

  file.close();
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

Sprite &LevelResources::getGroundSprite()
{
  return groundSprite;
}

Color LevelResources::getBackgroundColor()
{
  return backgroundColor;
}

Music *LevelResources::getBackgroundMusic()
{
  return &backgroundMusic;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "LevelResources.h"
#include "../config/ResourcesLocation.h"
#include "../config/Config.h"

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

  groundTexture.loadFromFile(groundPath);
  destructibleBoxTexture.loadFromFile(destructibleBoxPath);
  indestructibleBoxTexture.loadFromFile(indestructibleBoxPath);
  borderBoxTexture.loadFromFile(borderBoxPath);
  cornerBoxTexture.loadFromFile(cornerBoxPath);

  groundSprite.setTexture(groundTexture);
  groundSprite.setScale(SCALE_FACTOR, SCALE_FACTOR);

  string fileLocation = levelAssetsFolder(levelId) + BACKGROUND_COLOR_FILE;
  ifstream file(fileLocation);
  string line;
  while (getline(file, line))
  {
    if (!line.empty())
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
      else
      {
        cerr << "Error: La línea no contiene suficientes valores RGBA." << endl;
      }
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
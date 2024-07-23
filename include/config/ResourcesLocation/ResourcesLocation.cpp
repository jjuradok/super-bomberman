#include <iostream>

using namespace std;

string levelAssetsFolder(string levelId)
{
  return "resources/assets/levels/" + levelId + "/";
}

string playerTextureFolder(bool isPlayerOne, string direction)
{
  string playerFolder = isPlayerOne ? "p1/" : "p2/";
  return "resources/assets/textures/" + playerFolder + "self/" + direction + "/";
}

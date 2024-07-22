#include <iostream>

using namespace std;

string levelAssetsFolder(string levelId)
{
  return "assets/levels/" + levelId + "/";
}

string playerTextureFolder(bool isPlayerOne, string direction)
{
  string playerFolder = isPlayerOne ? "p1/" : "p2/";
  return "assets/textures/" + playerFolder + "self/" + direction + "/";
}

#ifndef RESOURCES_LOCATION_H
#define RESOURCES_LOCATION_H
#include <string>
using namespace std;

const string SETTINGS_FILE = "resources/settings.txt";
const string PLAYER_TEXTURE = "assets/textures/p1/self/player.png";
const string SECOND_PLAYER_TEXTURE = "assets/textures/p2/self/player.png";
const string BOMB_TEXTURE_P1_FOLDER = "assets/textures/p1/bomb/";
const string BOMB_TEXTURE_P2_FOLDER = "assets/textures/p2/bomb/";
const string TEST_LEVEL_LAYOUT = "resources/levels/aqua.txt";
const string EXPLOSION_TEXTURES_FOLDER = "assets/textures/explosion/";
const int EXPLOSION_ANIMATION_FRAMES = 4;
const int BOMB_ANIMATION_FRAMES = 3;

const string DESTRUCTIBLE_BOX_LEVEL_TEXTURE = "textures/box/destructible/single.png";
const string INDESTRUCTIBLE_BOX_LEVEL_TEXTURE = "textures/box/indestructible/single.png";
const string BORDER_BOX_LEVEL_TEXTURE = "textures/box/indestructible/border.png";
const string CORNER_BOX_LEVEL_TEXTURE = "textures/box/indestructible/corner.png";
const string BOTTOM_BORDER_BOX_LEVEL_TEXTURE = "textures/box/indestructible/bottom.png";
const string GROUND_LEVEL_TEXTURE = "textures/background/ground.png";

string levelAssetsFolder(string levelId);
#endif
#ifndef RESOURCES_LOCATION_H
#define RESOURCES_LOCATION_H
#include <string>
using namespace std;
const string FONT_FILE = "assets/fonts/pixel.ttf";
const string SETTINGS_FILE = "resources/settings.txt";
const string PLAYER_TEXTURE = "assets/textures/player.png";
const string SECOND_PLAYER_TEXTURE = "assets/textures/player2.png";
const string BOMB_TEXTURE = "assets/textures/bomb_p1.png";
const string BOMB_PLAYER_TWO_TEXTURE = "assets/textures/bomb_p2.png";
const string DESTRUCTIBLE_BOX_TEXTURE="assets/textures/destructible_box.png";
const string INDESTRUCTIBLE_BOX_TEXTURE = "assets/textures/indestructible_box.png";
const string TEST_LEVEL_LAYOUT = "resources/levels/aqua.txt";

const string DESTRUCTIBLE_BOX_LEVEL_TEXTURE = "textures/box/destructible/single.png";
const string INDESTRUCTIBLE_BOX_LEVEL_TEXTURE = "textures/box/indestructible/single.png";
const string BORDER_BOX_LEVEL_TEXTURE = "textures/box/indestructible/border.png";
const string CORNER_BOX_LEVEL_TEXTURE = "textures/box/indestructible/corner.png";
const string BOTTOM_BORDER_BOX_LEVEL_TEXTURE = "textures/box/indestructible/bottom.png";
const string GROUND_LEVEL_TEXTURE = "textures/background/ground.png";

string levelAssetsFolder(string levelId);
#endif
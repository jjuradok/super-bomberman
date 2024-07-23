#ifndef RESOURCES_LOCATION_H
#define RESOURCES_LOCATION_H
#include <string>
using namespace std;

const string SETTINGS_FILE = "resources/settings.txt";
const string LEVEL_IDS_FILE = "resources/levels/levels_data.txt";
const string FONT_FILE = "assets/fonts/pixel.ttf";
const string BOMB_TEXTURE_P1_FOLDER = "assets/textures/p1/bomb/";
const string BOMB_TEXTURE_P2_FOLDER = "assets/textures/p2/bomb/";
const string EXPLOSION_TEXTURES_FOLDER = "assets/textures/explosion/";

const string DESTRUCTIBLE_BOX_LEVEL_TEXTURE = "textures/box/destructible/single.png";
const string INDESTRUCTIBLE_BOX_LEVEL_TEXTURE = "textures/box/indestructible/single.png";
const string BORDER_BOX_LEVEL_TEXTURE = "textures/box/indestructible/border.png";
const string CORNER_BOX_LEVEL_TEXTURE = "textures/box/indestructible/corner.png";
const string BOTTOM_BORDER_BOX_LEVEL_TEXTURE = "textures/box/indestructible/bottom.png";
const string GROUND_LEVEL_TEXTURE = "textures/background/ground.png";
const string BACKGROUND_COLOR_FILE = "config/background_color.txt";
const string LEVEL_BACKGROUND_MUSIC = "music/background.mp3";

const string P1_TEXTURE_DOWN_FOLDER = "assets/textures/p1/self/down/";
const string P1_TEXTURE_UP_FOLDER = "assets/textures/p1/self/up/";
const string P1_TEXTURE_LEFT_FOLDER = "assets/textures/p1/self/left/";
const string P1_TEXTURE_RIGHT_FOLDER = "assets/textures/p1/self/right/";
const string P2_TEXTURE_DOWN_FOLDER = "assets/textures/p2/self/down/";
const string P2_TEXTURE_UP_FOLDER = "assets/textures/p2/self/up/";
const string P2_TEXTURE_LEFT_FOLDER = "assets/textures/p2/self/left/";
const string P2_TEXTURE_RIGHT_FOLDER = "assets/textures/p2/self/right/";


string levelAssetsFolder(string levelId);
string playerTextureFolder(bool isPlayerOne, string direction);
#endif
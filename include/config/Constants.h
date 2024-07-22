#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <vector>
using namespace std;

enum TILES {
  EMPTY_TILE = '-',
  SOLID_TILE = 'O',
  DESTRUCTIBLE_TILE = 'X',
  BORDER = '*',
};

enum CollisionTiles
{
  DESTRUCTIBLE = DESTRUCTIBLE_TILE,
  INDESTRUCTIBLE = SOLID_TILE,
};

const vector<char> COLLISION_TILES = {DESTRUCTIBLE, BORDER ,INDESTRUCTIBLE};

const char PLAYER_ONE_ID = '1';
const char PLAYER_TWO_ID = '2';

const string RIGHT = "right";
const string LEFT = "left";
const string UP = "up";
const string DOWN = "down";

const int EXPLOSION_ANIMATION_FRAMES = 4;
const int BOMB_ANIMATION_FRAMES = 3;
const int PLAYER_ANIMATION_FRAMES = 3;
const int PLAYER_TEXTURE_UP_DEFAULT_FRAME = 1;
const int PLAYER_TEXTURE_DOWN_DEFAULT_FRAME = 1;
const int PLAYER_TEXTURE_LEFT_DEFAULT_FRAME = 0;
const int PLAYER_TEXTURE_RIGHT_DEFAULT_FRAME = 0;

#endif

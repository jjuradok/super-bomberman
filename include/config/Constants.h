#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <vector>
using namespace std;

enum TILES {
  EMPTY_TILE = '-',
  SOLID_TILE = 'O',
  DESTRUCTIBLE_TILE = 'X'
};

enum CollisionTiles
{
  DESTRUCTIBLE = DESTRUCTIBLE_TILE,
  INDESTRUCTIBLE = SOLID_TILE
};
const vector<char> COLLISION_TILES = {DESTRUCTIBLE, INDESTRUCTIBLE};

const char PLAYER_ONE_ID = '1';
const char PLAYER_TWO_ID = '2';

#endif

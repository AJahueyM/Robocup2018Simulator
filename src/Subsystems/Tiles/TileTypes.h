//
// Created by Abiel on 1/3/18.
//

#ifndef ROBOCUP2018SIMULATOR_TILETYPES_H
#define ROBOCUP2018SIMULATOR_TILETYPES_H

#include "Wall.h"

enum TileStatus {
  Exists,
  NonExistent,
  Visited,
  NonVisisted
};

enum TileType {
  Normal,
  Bumper,
  Checkpoint,
  Forbidden
};

enum TileVictim {
  Heat,
  NoTileVictim
};

struct TileWalls {
  Wall top, left, bottom, right;
};

#endif //ROBOCUP2018SIMULATOR_TILETYPES_H

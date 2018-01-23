//
// Created by Alberto Jahuey on 12/20/2017.
//

#ifndef ROBOCUP2018SIMULATOR_TILE_H
#define ROBOCUP2018SIMULATOR_TILE_H

#include <vector>
#include "Wall.h"
#include "../../EctoSettings.h"
#include "TileTypes.h"
using namespace std;


class Tile {
public:
    Tile( TileStatus status, TileType type, TileWalls &walls, TileVictim victim = NoTileVictim);

    void setType(TileType &newType);

    void setWalls(TileWalls &newWalls);

    void setStatus(TileStatus &newStatus);

    TileType &getType();

    TileWalls &getWalls();

    const TileWalls &getWalls() const;

    TileStatus &getStatus();

protected:

private:
    TileStatus status;
    TileType type;
    TileWalls walls;
    TileVictim victim;
};


#endif //ROBOCUP2018SIMULATOR_TILE_H

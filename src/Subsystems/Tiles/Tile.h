//
// Created by Alberto Jahuey on 12/20/2017.
//

#ifndef MYPROJECT_TILE_H
#define MYPROJECT_TILE_H

#include <vector>
#include "Wall.h"
#include "../../EctoSettings.h"
using namespace std;

enum Status {
    Exists,
    NonExistent,
    Visited,
    NonVisisted
};

enum Type {
    Normal,
    Bumper,
    Checkpoint,
    Forbidden
};

enum TileVictim {
    Heat,
    NoTileVictim
};

struct Walls {
    Wall top, left, bottom, right;
};

class Tile {
public:
    Tile( Status status, Type type, Walls &walls, TileVictim victim = NoTileVictim);

    void setType(Type &newType);

    void setWalls(Walls &newWalls);

    void setStatus(Status &newStatus);

    Type &getType();

    Walls &getWalls();

    const Walls &getWalls() const;

    Status &getStatus();

protected:

private:
    Status status;
    Type type;
    Walls walls;
    TileVictim &victim;
};


#endif //MYPROJECT_TILE_H

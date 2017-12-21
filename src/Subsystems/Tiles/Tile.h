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
    Wall *top, *left, *bottom, *right;
};

class Tile {
public:
    Tile(int x, int y, Status status, Type type, Walls &walls, TileVictim victim = NoTileVictim);

    void setType(Type &newType);

    void setWalls(Walls &newWalls);

    void setStatus(Status &newStatus);

    void setWidth(int newWidth);

    Type &getType();

    Walls &getWalls();

    const Walls &getWalls() const;

    Status &getStatus();

    int getWidth();

    void setX(int x);

    void setY(int y);

    int getX() const;

    int getY() const;

protected:

private:
    EctoSettings& settings  = EctoSettings::getInstance();
    int width;
    int centerX, centerY;
    Status status;
    Type type;
    Walls walls;
    TileVictim &victim;
};


#endif //MYPROJECT_TILE_H

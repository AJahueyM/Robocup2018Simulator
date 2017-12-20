//
// Created by Alberto Jahuey on 12/20/2017.
//

#ifndef MYPROJECT_TILE_H
#define MYPROJECT_TILE_H

#include <vector>

enum TileStatus {
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
using namespace std;

class Tile {
public:
protected:
private:
    TileStatus status;
    Type type;
    bool wallTop, wallBottom, wallLeft, wallRight;
};


#endif //MYPROJECT_TILE_H

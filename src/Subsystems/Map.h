//
// Created by alber on 1/22/2018.
//

#ifndef MYPROJECT_MAP_H
#define MYPROJECT_MAP_H
#include "Tiles/TileGrid.h"

class Map {
public:
    Map(const TileGrid& grid);
protected:
    const TileGrid& grid;
private:
};


#endif //MYPROJECT_MAP_H

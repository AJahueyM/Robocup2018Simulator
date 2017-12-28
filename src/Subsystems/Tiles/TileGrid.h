//
// Created by Alberto Jahuey on 12/21/2017.
//

#ifndef MYPROJECT_TILEGRID_H
#define MYPROJECT_TILEGRID_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "Tile.h"
using namespace std;
class TileGrid {
public:
    TileGrid( int width, int height, int sizeX, int sizeY);
    vector<vector<Tile>>& getGrid();
protected:
    vector<vector<Tile>> tileGrid;
private:

};


#endif //MYPROJECT_TILEGRID_H

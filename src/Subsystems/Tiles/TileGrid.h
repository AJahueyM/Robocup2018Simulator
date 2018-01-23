//
// Created by Alberto Jahuey on 12/21/2017.
//

#ifndef ROBOCUP2018SIMULATOR_TILEGRID_H
#define ROBOCUP2018SIMULATOR_TILEGRID_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "Tile.h"
using namespace std;
class TileGrid {
public:
    TileGrid(int sizeX, int sizeY);
    TileGrid(vector<vector<Tile>> &tileGrid);
    int getSizeX();
    int getSizeY();
    vector<vector<Tile>>& getGrid();
protected:
    vector<vector<Tile>> tileGrid;
private:

};


#endif //ROBOCUP2018SIMULATOR_TILEGRID_H

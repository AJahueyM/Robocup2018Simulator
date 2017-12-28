//
// Created by Alberto Jahuey on 12/21/2017.
//

#include "TileGrid.h"

TileGrid::TileGrid(int width, int height, int sizeX, int sizeY) {
    for(int i = 0 ; i < sizeX; ++i){
        tileGrid.emplace_back();
        for(int j = 0; j < sizeY; ++j){
            Walls wall;
            tileGrid[i].emplace_back(Tile(Exists, Normal, wall));

        }
    }
}

vector<vector<Tile>>& TileGrid::getGrid() {
    return tileGrid;
}



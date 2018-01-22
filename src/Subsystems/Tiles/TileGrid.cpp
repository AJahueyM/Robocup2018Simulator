//
// Created by Alberto Jahuey on 12/21/2017.
//

#include "TileGrid.h"

TileGrid::TileGrid(int sizeX, int sizeY) {
    for(int i = 0 ; i < sizeX; ++i){
        tileGrid.emplace_back();
        for(int j = 0; j < sizeY; ++j){
            Walls wall;
            wall.top.setExists(true);
            wall.bottom.setExists(true);
            wall.right.setExists(true);
            wall.left.setExists(true);

            tileGrid[i].emplace_back(Tile(Exists, Normal, wall));

        }
    }
}

TileGrid::TileGrid(vector<vector<Tile>> &tiles) : tileGrid(tiles) {
    this->tileGrid = tiles;
}
vector<vector<Tile>> TileGrid::getGrid() const {
    return tileGrid;
}


int TileGrid::getSizeX() {
    return tileGrid.size();
}

int TileGrid::getSizeY() {
    return tileGrid[0].size();
}

void TileGrid::setGrid(vector<vector<Tile>> &tileGrid) {
    this->tileGrid = tileGrid;
}




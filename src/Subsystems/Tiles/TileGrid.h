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
    explicit TileGrid(int sizeX, int sizeY);
    explicit TileGrid(vector<vector<Tile>>& tiles);
    int getSizeX();
    int getSizeY();
    vector<vector<Tile>> getGrid() const;
    void setGrid(vector<vector<Tile>> &tileGrid);
protected:
    vector<vector<Tile>> tileGrid;
private:

};


#endif //MYPROJECT_TILEGRID_H

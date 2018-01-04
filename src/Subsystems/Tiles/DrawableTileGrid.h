//
// Created by Alberto Jahuey on 12/27/2017.
//

#ifndef ROBOCUP2018SIMULATOR_DRAWABLETILEGRID_H
#define ROBOCUP2018SIMULATOR_DRAWABLETILEGRID_H
#include "TileGrid.h"
#include "DrawableTile.h"

class DrawableTileGrid {
public:
    explicit DrawableTileGrid(int x, int y, int width, int height, TileGrid& grid);
    void draw(sf::RenderWindow &window);
    void update();
protected:
    int x, y, width, height;
    TileGrid& grid;
    vector<vector<DrawableTile>> drawableGrid;
private:
};


#endif //ROBOCUP2018SIMULATOR_DRAWABLETILEGRID_H

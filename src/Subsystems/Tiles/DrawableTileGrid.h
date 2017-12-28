//
// Created by Alberto Jahuey on 12/27/2017.
//

#ifndef MYPROJECT_DRAWABLETILEGRID_H
#define MYPROJECT_DRAWABLETILEGRID_H
#include "TileGrid.h"
#include "DrawableTile.h"

class DrawableTileGrid {
public:
    explicit DrawableTileGrid(TileGrid& grid);
    void draw(sf::RenderWindow &window);
    void update();
protected:
    TileGrid& grid;
    vector<vector<DrawableTile>> drawableGrid;
private:
};


#endif //MYPROJECT_DRAWABLETILEGRID_H

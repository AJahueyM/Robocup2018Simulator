//
// Created by Alberto Jahuey on 12/27/2017.
//

#include "DrawableTileGrid.h"

DrawableTileGrid::DrawableTileGrid(int x, int y, int width, int height, TileGrid& grid) : grid(grid) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;

    double tileWidth = width / grid.getSizeX();
    for(int i = 0; i < grid.getGrid().size(); ++i){
        drawableGrid.emplace_back();
        for(int j = 0; j < grid.getGrid()[i].size(); ++j){
            drawableGrid[i].emplace_back(DrawableTile(i, j, grid.getGrid()[i][j]));
            drawableGrid[i][j].setWidth(tileWidth);
            drawableGrid[i][j].setX(tileWidth / 2 + (tileWidth * i));
            drawableGrid[i][j].setY(tileWidth / 2 + (tileWidth * j));

        }
    }
}

void DrawableTileGrid::draw(sf::RenderWindow &window) {
    for(const auto &x : drawableGrid){
        for(const auto &y : x){
            y.draw(window);
        }
    }
}

void DrawableTileGrid::update() {
    for(auto &x : drawableGrid){
        for(auto &y : x){

            y.update();
        }
    }
}

//
// Created by alber on 11/1/2017.
//
#include <SFML/Graphics.hpp>
#include "Subsystems/Tiles/Tile.h"
#include "Subsystems/Tiles/DrawableTile.h"
#include "Subsystems/Tiles/DrawableTileGrid.h"
#include <vector>
#include <iostream>

using namespace std;

#ifndef ROBOCUP2018SIMULATOR_SKETCH_H
#define ROBOCUP2018SIMULATOR_SKETCH_H
unsigned int WIDTH = 800;
unsigned int HEIGHT = 800;

class Sketch {
private:
    //Tile* tile;
    //DrawableTile* drawTile;
    TileGrid grid = TileGrid( 8, 8);
    DrawableTileGrid drawGrid = DrawableTileGrid(0,0,WIDTH, HEIGHT,grid);
public:

    void setup() {
        TileWalls wall;

        //drawTile = new DrawableTile(WIDTH/2,HEIGHT/2,*tile);
    }

    void update() {
        drawGrid.update();

    }

    void draw(sf::RenderWindow &window) {
        WIDTH = window.getSize().x;
        HEIGHT = window.getSize().y;

//        sf::RectangleShape x(sf::Vector2f(WIDTH, 4)), y(sf::Vector2f(4, HEIGHT));
//        x.setPosition(sf::Vector2f(0, HEIGHT/2 - 2));
//        y.setPosition(sf::Vector2f(WIDTH/2 - 2, 0));
//        x.setFillColor(sf::Color::Blue);
//        y.setFillColor(sf::Color::Black);
//
//        window.draw(x);
//        window.draw(y);


        drawGrid.draw(window);

    }
};

#endif //ROBOCUP2018SIMULATOR_SKETCH_H

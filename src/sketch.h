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

#ifndef MYPROJECT_SKETCH_H
#define MYPROJECT_SKETCH_H
unsigned int WIDTH = 800;
unsigned int HEIGHT = 800;

class Sketch {
private:
    Tile* tile;
    DrawableTile* drawTile;
    TileGrid grid = TileGrid(WIDTH, HEIGHT, 5, 5);
    DrawableTileGrid drawGrid = DrawableTileGrid(grid);
public:

    void setup() {
        Walls wall;
        tile = new Tile(Visited, Normal, wall);

        drawTile = new DrawableTile(WIDTH/2,HEIGHT/2,*tile);
    }

    void update() {
        //drawGrid.update();
        drawTile->update();
        Walls& wall = tile->getWalls();
        wall.bottom.setExists(sf::Keyboard::isKeyPressed(sf::Keyboard::A));
        wall.top.setExists(sf::Keyboard::isKeyPressed(sf::Keyboard::S));
        wall.right.setExists(sf::Keyboard::isKeyPressed(sf::Keyboard::D));
        wall.left.setExists(sf::Keyboard::isKeyPressed(sf::Keyboard::F));
    }

    void draw(sf::RenderWindow &window) {
        WIDTH = window.getSize().x;
        HEIGHT = window.getSize().y;

        sf::RectangleShape x(sf::Vector2f(WIDTH, 4)), y(sf::Vector2f(4, HEIGHT));
        x.setPosition(sf::Vector2f(0, HEIGHT/2 - 2));
        y.setPosition(sf::Vector2f(WIDTH/2 - 2, 0));
        x.setFillColor(sf::Color::Blue);
        y.setFillColor(sf::Color::Black);
        drawTile->draw(window);

        window.draw(x);
        window.draw(y);


        //drawGrid.draw(window);

    }
};

#endif //MYPROJECT_SKETCH_H

//
// Created by Alberto Jahuey on 12/20/2017.
//

#ifndef MYPROJECT_DRAWABLETILE_H
#define MYPROJECT_DRAWABLETILE_H
#include "Tile.h"
#include <SFML/Graphics.hpp>
class DrawableTile : public Tile {
public:
    DrawableTile(int x, int y, Status status, Type type, Walls &walls, TileVictim victim = NoTileVictim);
    void draw(sf::RenderWindow &window);
    void update();
protected:
private:
    int lineWidth;
    vector<sf::RectangleShape> sides;
};


#endif //MYPROJECT_DRAWABLETILE_H

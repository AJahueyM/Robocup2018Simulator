//
// Created by Alberto Jahuey on 12/20/2017.
//

#ifndef MYPROJECT_DRAWABLETILE_H
#define MYPROJECT_DRAWABLETILE_H
#include "Tile.h"
#include <SFML/Graphics.hpp>
class DrawableTile{
public:
    DrawableTile(int x, int y, Tile& tile);
    void draw(sf::RenderWindow &window) const;
    void update();
    void setX(int x);
    void setY(int y);
    void setWidth(int width);
    int getX();
    int getY();
    int getWidth();
    int getLineWidth();
protected:
private:
    EctoSettings& settings  = EctoSettings::getInstance();
    Tile& tile;
    int centerX, centerY, width, lineWidth;
    vector<sf::RectangleShape> sides;
};


#endif //MYPROJECT_DRAWABLETILE_H

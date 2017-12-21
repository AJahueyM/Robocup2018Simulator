//
// Created by Alberto Jahuey on 12/20/2017.
//

#include "DrawableTile.h"

DrawableTile::DrawableTile(int x, int y, Status status, Type type, Walls &walls, TileVictim victim) : Tile(x, y, status,
                                                                                                           type, walls,
                                                                                                           victim) {
    for(int i = 0; i < 4; ++i)
        sides.emplace_back(sf::RectangleShape());
    update();
}

void DrawableTile::draw(sf::RenderWindow &window) {
    for(auto line : sides){
        window.draw(line);
    }
}

void DrawableTile::update() {
    sf::RectangleShape& top = sides[0];
    sf::RectangleShape& bottom = sides[1];

    sf::RectangleShape& right = sides[2];
    sf::RectangleShape& left =  sides[3];
    Walls& walls = getWalls();

    if(walls.top->getExists()) {
        top.setFillColor(sf::Color::Black);
    }else{
        top.setFillColor(sf::Color::Transparent);
    }

    if(walls.bottom->getExists()){
        bottom.setFillColor(sf::Color::Black);
    }else{
        bottom.setFillColor(sf::Color::Transparent);
    }

    if(walls.right->getExists()){
        right.setFillColor(sf::Color::Black);
    }else{
        right.setFillColor(sf::Color::Transparent);
    }

    if(walls.left->getExists()){
        left.setFillColor(sf::Color::Black);
    }else{
        left.setFillColor(sf::Color::Transparent);
    }

    lineWidth = getWidth()*.05;

    top.setSize(sf::Vector2f(getWidth(), lineWidth));
    bottom.setSize(sf::Vector2f(getWidth(), lineWidth));
    right.setSize(sf::Vector2f(lineWidth, getWidth()));
    left.setSize(sf::Vector2f(lineWidth, getWidth()));

    top.setPosition(getX() - getWidth()/2, getY() - getWidth()/2);
    bottom.setPosition(getX() - getWidth()/2, getY() + getWidth()/2 - lineWidth);
    right.setPosition(getX() + getWidth()/2 - lineWidth, getY() - getWidth()/2);
    left.setPosition(getX() - getWidth()/2, getY() - getWidth()/2);
}

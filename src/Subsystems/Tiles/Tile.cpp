//
// Created by Alberto Jahuey on 12/20/2017.
//

#include "Tile.h"

Tile::Tile(int x, int y, Status status, Type type, Walls &walls, TileVictim victim) : status(status), type(type), walls(walls),
                                                                          victim(victim) {
    settings.setCurrentGroup("Tiles");
    width = settings.getNumber("width");
    centerX = x - width/2;
    centerY = y - width/2;
}

void Tile::setType(Type &newType) {
    type = newType;
}

void Tile::setWalls(Walls &newWalls) {
    walls = newWalls;
}

void Tile::setStatus(Status &newStatus) {
    status = newStatus;
}

void Tile::setWidth(int newWidth) {
    width = newWidth;
}

Type &Tile::getType(){
    return type;
}

Walls &Tile::getWalls() {
    return walls;
}

const Walls &Tile::getWalls() const{
    return walls;
}

Status &Tile::getStatus(){
    return status;
}

int Tile::getWidth() {
    return width;
}

void Tile::setX(int x) {
    centerX = x;
}

void Tile::setY(int y) {
    centerY = y;
}

int Tile::getX() const{
    return centerX;
}

int Tile::getY() const{
    return centerY;
}


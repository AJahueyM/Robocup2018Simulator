//
// Created by Alberto Jahuey on 12/20/2017.
//

#include "Tile.h"

Tile::Tile(Status status, Type type, Walls &walls, TileVictim victim) : status(status), type(type), walls(walls),
                                                                          victim(victim) {
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


//
// Created by Alberto Jahuey on 12/20/2017.
//

#include "Tile.h"

Tile::Tile(TileStatus status, TileType type, TileWalls &walls, TileVictim victim) : status(status), type(type), walls(walls),
                                                                          victim(victim) {
}

void Tile::setType(TileType &newType) {
    type = newType;
}

void Tile::setWalls(TileWalls &newWalls) {
    walls = newWalls;
}

void Tile::setStatus(TileStatus &newStatus) {
    status = newStatus;
}

TileType &Tile::getType(){
    return type;
}

TileWalls &Tile::getWalls() {
    return walls;
}

const TileWalls &Tile::getWalls() const{
    return walls;
}

TileStatus &Tile::getStatus(){
    return status;
}


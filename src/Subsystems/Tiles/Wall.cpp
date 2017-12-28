//
// Created by Alberto Jahuey on 12/20/2017.
//

#include "Wall.h"

Wall::Wall(bool exists, VisualVictim wallVictim) : exists(exists), wallVictim(wallVictim) {

}

bool Wall::getExists() const{
    return exists;
}

VisualVictim Wall::getVisualVictim() const{
    return wallVictim;
}

void Wall::setExists(bool exists) {
    this->exists = exists;
}

void Wall::setVisualVictim(VisualVictim wallVictim) {
    this->wallVictim = wallVictim;
}


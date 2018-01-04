//
// Created by Alberto Jahuey on 12/20/2017.
//

#ifndef ROBOCUP2018SIMULATOR_WALL_H
#define ROBOCUP2018SIMULATOR_WALL_H

#include "WallTypes.h"

class Wall {
public:
    explicit Wall(bool exists = false, VisualVictim wallVictim = NoWallVictim);

    bool getExists() const;

    VisualVictim getVisualVictim() const;

    void setExists(bool exists);

    void setVisualVictim(VisualVictim wallVictim);

protected:

private:
    bool exists;
    VisualVictim wallVictim;
};


#endif //ROBOCUP2018SIMULATOR_WALL_H

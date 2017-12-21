//
// Created by Alberto Jahuey on 12/20/2017.
//

#ifndef MYPROJECT_WALL_H
#define MYPROJECT_WALL_H

enum VisualVictim {
    Stable,
    Harmed,
    Unharmed,
    NoWallVictim
};

class Wall {
public:
    Wall(bool exists, VisualVictim wallVictim);

    bool getExists() const;

    VisualVictim getVisualVictim() const;

protected:

private:
    bool exists;
    VisualVictim wallVictim;
};


#endif //MYPROJECT_WALL_H

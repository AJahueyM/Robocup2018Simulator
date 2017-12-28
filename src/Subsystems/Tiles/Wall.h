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


#endif //MYPROJECT_WALL_H

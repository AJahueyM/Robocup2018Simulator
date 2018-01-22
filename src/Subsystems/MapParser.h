//
// Created by alber on 1/3/2018.
//

#ifndef MYPROJECT_MAPPARSER_H
#define MYPROJECT_MAPPARSER_H
#include <string>
#include <vector>
#include <windows.h>
#include "Tiles/Tile.h"
#include "Tiles/TileGrid.h"
#include <iostream>
#include <fstream>
#include "../spdlog/spdlog.h"

namespace spd = spdlog;

using namespace std;

class StartingMapConfig {
public:
    StartingMapConfig(int sizeX, int sizeY, int startingRobotX, int startingRobotY);
protected:
    int sizeX,  sizeY,  robotX, robotY;
public:
    int getSizeX() const;

    int getSizeY() const;

    int getRobotX() const;

    int getRobotY() const;

private:
};
class MapParser {
public:
    explicit MapParser(const string& searchDir);
    TileGrid getGrid(const string& gridName);
protected:
    vector<string> getPathsOnDir();

private:
    static shared_ptr<spd::logger> log = spd::stdout_color_mt("Map Parser");
    string path;

};


#endif //MYPROJECT_MAPPARSER_H
